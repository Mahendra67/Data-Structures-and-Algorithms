#include<iostream>
#include<bits/stdc++.h>
//Alien Dictionary GFG
/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of 
standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid 
order and output will be 1 if the order of string returned by the function is correct else 0 
denoting incorrect string returned.
*/
using namespace std;


//Intuition: In question, the alphabets are ordered something before something
/*
you should have got a "feeling" that when something is prioritized over others
we can use the concept of topo sort, to get the complete priority order*/
//Hence, try topological sort

/*
For given input:
since k = 4, assume  A:0, B:1, C:2, D:3
Now, make directed edges according to given pairs, then return topo sort of that graph
*/

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        
        //Create a graph of alien word relation
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            //Compare till the minimum length of the two 2 strings
            int len = min(s1.length(), s2.length());
            
            for(int j = 0; j<len; j++){
                if(s1[j] != s2[j]){
                    //If the current char is not equal, means the top one must comes first
                    //Create a directed edge from s1[j] -> s2[j]
                    //And to store nodes in 0-indexing order, subtract 'a' from them
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    //No more checking needed for the 2 pair of words
                    break;
                }
            }
        }
        
        //Apply topo sort 
        string ans;
        vector<int> indegree(K,0);
        
        //Count indegree
        for(int i=0; i<K; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        //Push nodes with indegree 0 in queue
        queue<int> q;
        
        for(int i=0; i<K; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            char n = node + 'a';
            ans += n;
            q.pop();
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return ans;
        
        }
};


int main(){
    
    return 0;
}