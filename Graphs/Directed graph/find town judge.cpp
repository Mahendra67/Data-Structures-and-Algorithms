#include<iostream>
#include<bits/stdc++.h>
//Find the town judge LeetCode 997
/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/
using namespace std;

/*-----------------------------------------------------------------------------------------------------------------*/
/*Approach 1 : TownJudge must have inDegree as n-1 (everybody should trust TJ)
Outdegree of TownJudge must be 0 (it doesn't trusts anyone)
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n+1,0);
        vector<int> outDegree(n+1,0);
        
        for(auto it: trust){
            // it[0] -> it[1] , that means it[0] trusts it[1]
            outDegree[it[0]]++;
            inDegree[it[1]]++;
        }
        
        int Judge = -1;
        for(int i=1; i<n+1; i++){
            if(inDegree[i] == n-1 && outDegree[i] == 0){
                Judge = i;
                break;
            }
        }
        
        return Judge;
    }
};

/*----------------------------------------------------------------------------------------------------------------*/



int main(){
    
    return 0;
}