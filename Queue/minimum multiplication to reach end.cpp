#include<iostream>
#include<bits/stdc++.h>
//Minimum multiplication to reach end
/*
Given start, end and an array arr of n numbers. At each step, start is multiplied 
with any number in the array and then mod operation with 100000 is done to get the 
new start.

Your task is to find the minimum steps in which end can be achieved starting from 
start. If it is not possible to reach end, then return -1.
*/
using namespace std;

/*----------------------------------------------------------------------------------------------------------*/

//Using unordered_set to store unique start values, so that it doesn't have to do same iterations again.
//GIVES TLE 
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        
        /*Unordered set is used to store all start values (so that we only store unique value
        and if we find number is repeating (occurs more than 1) -> end is not reachable)*/
        unordered_set<int> startValues;
        
        int steps = 0;
        //pair stores : {steps, node}
        queue<pair<int, int>> q;
        
        q.push({steps, start});
        
        while(!q.empty()){
            auto it = q.front();
            int step = it.first;
            int node = it.second;
            q.pop();
            
            //If you reach end value return steps (since bfs -> steps will be minimum)
            if(node == end){
                return step;
            }
            
            for(int i=0; i<n; i++){
                int newStart = (node*arr[i]);
                //mod 100000 of anything smaller than 100000 will always give the same number.
                if(newStart > 100000){
                    newStart = newStart % 100000;
                }
                
                //If it is unique start value, add to the queue and the unordered_set
                if(startValues.find(newStart) == startValues.end()){
                    startValues.insert(newStart);
                    
                    //Push into the queue
                    q.push({step+1, newStart});
                }
            }
        }
        
        //If it reaches here, means you didn't reach the end nodes and values are repeating
        return -1;
    }
};

/*----------------------------------------------------------------------------------------------------------*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        
        /*Start values can be from 0 to 99999.
        Treat these as nodes, and whenever you reach any unvisited node, mark it as visited and 
        push into queue along with steps.
        
        In end, if iterations end, and the end node is still not visited, return -1*/
        vector<int> startValues_vis(100000,0);
        
        int steps = 0;
        //pair stores : {steps, node}
        queue<pair<int, int>> q;
        startValues_vis[start] = 1;
        
        q.push({steps, start});
        
        while(!q.empty()){
            auto it = q.front();
            int step = it.first;
            int node = it.second;
            q.pop();
            
            //Checking if we got end node
            // if(node == end){
            //     return step;
            // }
            
            for(int i=0; i<n; i++){
                int newStart = (node*arr[i]);
                //mod 100000 of anything smaller than 100000 will always give the same number.
                if(newStart >= 100000){
                    newStart = newStart % 100000;
                }
                
                //If not visited, then add to queue
                /*If it is already visited, no point in pushing that into queue, as
                it will just repeat older values.*/
                if(!startValues_vis[newStart]){
                    //Mark as visited
                    startValues_vis[newStart] = 1;
                    
                    //Check if we got the end Value or not
                    /*Checking here is better, since in case we found 'end' from first value of
                    given array, we don't need to check the whole array.*/
                    if(newStart == end){
                        return step+1;
                    }
                    
                    q.push({step+1, newStart});
                }
            }
        }
        
        //If it reaches here, means you didn't reach the end nodes and values are repeating
        return -1;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}