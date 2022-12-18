#include<iostream>
#include<bits/stdc++.h>
//295 leetcode
/*
Implement the mean finder class
*/
using namespace std;

//Approach 1 : But gives TLE
class MedianFinder {
public:
    vector<int> v1;
    int count;
    
    void addNum(int num) {
        v1.push_back(num);
        count++;
        //Sort it because median is middle value of ordered(sorted) integer list
        sort(v1.begin(),v1.end());
    }
    
    double findMedian() {
        if(count%2==0){
            double data = ( v1[(count-1)/2] + v1[count/2] ) / 2.0;
            return data;
        }else{
            return (double)v1[count/2];
        }
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){

    //Approach 1: Intuitive solution
    //But gives TLE since input size if 10^5
    /*
    Vector data structure used here.
    As you add to the vector, sort it at every addition(since median is middle of sorted list), and keep track of no. of elements(n).
    If n is even, then return the avg of middle 2 elements. If n is odd, then return the middle element.
    */
    
    return 0;
}