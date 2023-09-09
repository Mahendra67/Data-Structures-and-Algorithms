#include<bits/stdc++.h>
using namespace std;

class SegTree{
public:
    vector<int> seg;
    vector<int> lazy;

    SegTree(vector<int>& arr){
        int n = arr.size();
        seg.resize(4*n, -1);
        lazy.resize(4*n, 0);
    }

    //idx -> start from 0th index
    //left -> smallest index
    //right -> largest index
    void build(int idx, int left, int right, vector<int>& arr){
        //Base case
        if(left == right){
            seg[idx] = arr[left];
            return;
        }

        int mid = (right-left)/2 + left;

        //build left child
        build(2*idx+1, left, mid, arr);

        //build right right
        build(2*idx+2, mid+1, right, arr);


        //while backtracking, precompute the ans for this range
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];

        return;
    }


    //Queries here
    //SegIdx -> starting index of segTree
    //segNodeLeft -> smallest index of array
    //segNodeRight -> largest index of array
    int query(int segIdx, int segNodeLeft, int segNodeRight, int queryLeft, int queryRight){
        //SegNode range lies completely inside the query range
        //It will fully contribute to answer
        if(queryLeft <= segNodeLeft && queryRight >= segNodeRight){
            return seg[segIdx];
        } 


        //SegNode range lies outside the query range
        //Doesn't contribute to answer
        if(segNodeRight < queryLeft || segNodeLeft > queryRight){
            //return a value which wont contribute to answer
            return 0;
        }


        //Some part of Query node range lies inside(exclusive) segNode Range
        //Partially overlaps
        int mid = (segNodeRight - segNodeLeft)/2 + segNodeLeft;

        int left = query(2*segIdx+1, segNodeLeft, mid, queryLeft, queryRight);
        int right = query(2*segIdx+2, mid+1, segNodeRight, queryLeft, queryRight);

        return left + right; 
    }



    //Point update -> update on only 1 index in original array (logN)
    void pointUpdate(int segIdx, int segNodeLeft, int segNodeRight, int idx, int val){
        if(segNodeRight  == segNodeLeft){
            seg[segIdx] += val;
        }else{
            //check in which of the children node the idx is in
            int mid = (segNodeRight - segNodeLeft)/2 + segNodeLeft;

            if(idx >= segNodeLeft && idx <= mid){
                pointUpdate(2*segIdx+1, segNodeLeft, mid, idx, val);
            }else{
                pointUpdate(2*segIdx+2, mid+1, segNodeRight, idx, val);
            }

            //while coming back, add the condition
            seg[segIdx] = seg[2*segIdx+1] + seg[2*segIdx+2];
        }
    }


    //Range update
    void rangeUpdate(int segIdx, int segNodeLeft, int segNodeRight, int qL, int qR, int val){
        //check if there are pending updates left in dummy tree
        if(lazy[segIdx] != 0){
            seg[segIdx] += lazy[segIdx];

            //dont update the children nodes now -> lazy propagation
            //pass info that there are pending updates in this subtree 
            //store that info in lazy tree
            if(segNodeRight != segNodeRight){
                //ensure it has children nodes
                lazy[segIdx*2+1] = lazy[segIdx];
                lazy[segIdx*2+2] = lazy[segIdx]; 
            }

            lazy[segIdx] = 0;
        }


        //Now try to update the new value
        //If curr node range is completely inside the given update range
        if(segNodeLeft >= qL && segNodeRight <= qR){
            //we can calculate all the nodes contribution by calculating
            //no of nodes inside this range
            int nodesNum = segNodeRight-segNodeLeft+1;
            seg[segIdx] += nodesNum*val;

            //lazy propagation
            if(segNodeRight != segNodeLeft){
                lazy[2*segIdx+1] = val;
                lazy[2*segIdx+2] = val;
            }

            return;
        }


        //if it is completely outside the range
        if(segNodeLeft > qR || segNodeRight < qL){
            return;
        }


        //If query partially overlaps its range with current Node range
        int mid = (segNodeRight - segNodeLeft)/2 + segNodeLeft;
        rangeUpdate(2*segIdx+1, segNodeLeft, mid, qL, qR, val);
        rangeUpdate(2*segIdx+2, mid+1, segNodeRight, qL, qR, val);

        seg[segIdx] = seg[2*segIdx+1] + seg[2*segIdx+2];
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}