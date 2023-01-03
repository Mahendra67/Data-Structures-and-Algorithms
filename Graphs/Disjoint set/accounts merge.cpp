#include<iostream>
#include<bits/stdc++.h>
//Accounts Merge LeetCode 721
/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element 
accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there 
is some common email to both accounts. Note that even if two accounts have the same name, they may belong 
to different people as people could have the same name. A person can have any number of accounts initially, 
but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account 
is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned 
in any order.
*/
using namespace std;

/*-----------------------------------------------------------------------------------------------------------------*/

/*
DSU Approach:
Treat all the accounts[i][0] (names) as individual nodes. 
Now, map all the emails with their respective nodes. If an email has already been mapped to 
some other node, then attach the current node with that node(the one that the email has been already mapped to) using disjoint set (Union by size method).

Then iterate over the map formed, and push the emails into their respective node's ultimate
parent array in array of vectors (mergedMail vector<vector<string>>). And sort them.

Now, in 'ans' vector of vector, push the name (account[i][0]) first into the temp vector, and then push all the emails from respective node in mergedMail vector formed above. Only push if mergedMail[i] is not empty.
*/

class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    //Find ult parent with path compression
    int findUltParent(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findUltParent(parent[node]);
    }
    
    //Union by Size
    void unionBySize(int u, int v){
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        
        if(ult_u == ult_v){
            return;
        }
        
        if(size[ult_u] > size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        
        return;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        DisjointSet ds(n);
        
        //Unordered map to store {emails -> node}
        unordered_map<string,int> mapEmailNode;
        for(int i=0; i<n; i++){
            //Start from 1 index as name is at zero index
            for(int j=1; j<accounts[i].size(); j++){
                //Check if current email is already mapped to some index
                if(mapEmailNode.find(accounts[i][j]) != mapEmailNode.end()){
                    //If yes, then attach the current node to that mapped node
                    //current node -> i
                    //mapped node -> mapEmailNode[string]
                    int mapNode = mapEmailNode[accounts[i][j]];
                    ds.unionBySize(i, mapNode);
                }else{
                    //Add it into the map
                    mapEmailNode[accounts[i][j]] = i;
                }
            }
        }
        
        //Map and groups both are now created
        //Merge the emails 
        vector<vector<string>> merge(n);
        
        for(auto it: mapEmailNode){
            string email = it.first;
            //Push it in its ultimate parent node index
            int ultNode = ds.findUltParent(it.second);
            
            merge[ultNode].push_back(email);
        }
        
        //Now sort the emails and add the names(only add if emails are not empty in that row)
        vector<vector<string>> ans;
        
        for(int i=0; i<n; i++){
            if(merge[i].size() == 0){
                continue;
            }
            //If row not empty, sort the merge[i] array and add the name before it
            vector<string> temp;
            //Add name
            temp.push_back(accounts[i][0]);
            //Sort the merge[i] array
            sort(merge[i].begin(), merge[i].end());
            //Push the merge[i] array into temp
            for(auto it: merge[i]){
                temp.push_back(it);
            }
            
            //Now push the temp vector into ans
            ans.push_back(temp);
        }
        
        return ans;
    }
};

/*-----------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}