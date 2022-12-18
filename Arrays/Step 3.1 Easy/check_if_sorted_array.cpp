#include<iostream>
#include<vector>
//Check if array is sorted and rotated
using namespace std;

bool check(vector<int>& nums){
    //There can only be one breakpoints
    int size = nums.size();
    int count = 0;
    for(int i =0; i<size ;i++){
        //(i+1)%size is done so that it doesnt go out of bound
        //And works in circular manner
        if(nums[i]>nums[(i+1)%size]){
            count++;
        }
        if(count>1){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> nums = {7,8,8,10,2,3,3,6,6};
    cout<<check(nums);
    return 0;
}