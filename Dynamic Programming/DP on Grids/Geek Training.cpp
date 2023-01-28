#include<iostream>
#include<bits/stdc++.h>
//Geek's Training GFG

/*
Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and 
Learning Practice. each activity has the same point on each day. as Geek wants to improve all his skills, he can't 
do the same activity on two consecutive days, help Geek to maximize his merit points as we were given a 2D array 
of n*3 points corresponding to each day and activity.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
0   ->  oth task
1   ->  1th task
2   ->  2nd task
3   ->  no tasks done

Approach:
To keep track of lastTask done, pass the index of lastTask done in parameters.
Consider all the points that you can gather by doing tasks except the lastTask index.
Keep updating as you get a bigger maxPoint.
*/
class Solution {
  public:
    int maxPoint(int day, int lastTask, vector<vector<int>>& points, vector<vector<int>>& dp){
        //Base case:
        if(day == 0){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i != lastTask){
                    maxi = max(maxi, points[day][i]);
                }
            }
            return dp[day][lastTask] = maxi;
        }
        
        if(dp[day][lastTask] != -1){
            return dp[day][lastTask];
        }
        
        
        //When day is more than 0 upto n-1
        int maxi = 0;
        for(int i=0; i<3; i++){
            //Only consider those tasks which have not been done on previous day
            if(i != lastTask){
                //points = currentTaskpoints + remaining day points
                int currPoint = points[day][i] + maxPoint(day-1, i, points, dp);
                
                maxi = max(maxi, currPoint);
            }
        }
        
        return dp[day][lastTask] = maxi;
    }
    
    
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        //2 variables that can change : day, lastTask
        //day ->0 to n-1,    lastTask:0 to 3
        vector<vector<int>> dp(n, vector<int> (4, -1));
        
        //Convert 1 based indexing day to 0-based indexing 
        return maxPoint(n-1, 3, points, dp);
    }
};

/*-----------------------------------------------------------------------------------------------------------*/

//Tabulation Approach
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int> (3, -1));
        
        //Base case:
        /*
        When day becomes zero: LastTaskDone can be 0,1,2
        */
        //When zero index is lastTask : give max of 1,2
        dp[0][0] = max(points[0][1], points[0][2]);
        //When first index is lastTask : give max of 0,2
        dp[0][1] = max(points[0][0], points[0][2]);
        
        dp[0][2] = max(points[0][0], points[0][1]);
        
        
        for(int day=1; day<n; day++){
            for(int last=0; last<3; last++){
                int maxi = 0;
                for(int task=0; task<3; task++){
                    if(task != last){
                        int currPoint = points[day][task] + dp[day-1][task];
                        
                        maxi = max(maxi, currPoint);
                    }
                }
                
                dp[day][last] = maxi;
            }
        }
        
        //From the last row of dp, return the maxPoint that you get
        int m =  max(dp[n-1][0], dp[n-1][1]);
        m = max(m, dp[n-1][2]);
        
        return m;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/