#include<iostream>
#include<bits/stdc++.h>
//N Meetings GFG

/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where 
start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one 
meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

using namespace std;

/*-----------------------------------------------------------------------------------------------------------*/

/*
TC    :
SC    :
*/

bool custom_cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    
    return a.second < b.second;
}
class Solution
{
    /*
    Sort by ending time in ascending order. If next meeting starting time is more(or equal) than current meeting ending time
    , take that meeting into consideration
    */
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        
        for(int i=0; i<n; i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), custom_cmp);
        
        int count = 1;
        //endTime for prev considered meeting
        int PrevEndTime = v[0].second;
        for(int i=0; i<n; i++){
            if(PrevEndTime < v[i].first){
                count++;
                PrevEndTime = v[i].second;
            }
        }
        
        return count;
    }
};

/*-----------------------------------------------------------------------------------------------------------*/