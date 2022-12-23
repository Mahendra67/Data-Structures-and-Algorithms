#include<iostream>
#include<map>
#include<vector>
//Remove duplicates from sorted array
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 1
int removeDuplicates(vector<int>& nums){
    //No. of duplicates
    int m=0;
    int size = nums.size();
    //Using map
    map<int,int> mpp;
    vector<int>::iterator it = nums.begin();
    while(it!=nums.end()){
        mpp[*it]++;
        //If more than 1 occurence remove it
        if(mpp[*it]>1){
            nums.erase(it);
            m++;
            //Since after removing, the iterator moves one front(it++)
            //But the vector elements is pushed 1 front to fill the empty space created
            //Hence, after removing every duplicate, you need to move iterator one back
            it--;
        }
        it++;
    }
    return size-m;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 2
int removeDuplicates(vector<int>& nums) {
    int val = nums[0];
    int count = 0;
    int counter = 1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==val){
            count++;
        }else{
            nums[i-count+1] = nums[i];
            val = nums[i];
            //to keep track of no. of unique elements
            //Initialized to 1 since this else condition runs when its finds 2nd unique element
            counter++;
        }
    }
    return counter;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Approach 3
int removeDuplicates(vector<int>& nums) {
    int index = 0;
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] != nums[i - 1]) {
            //Enters this loop if it encounters a unique element
            nums[++index] = nums[i];
            //At first iteration, stores the element at index 1 and increments the index by 1
        }
    }
    //Returning index+1 , since we ran our loop from 1 to size-1
    //hence, we need to include the first element too.
    return index + 1;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    vector<int> nums = {1,1,1,2,3,4,5,6,6,6,7,8,9};

    //Approach 1
    //Use map and count no of occurences, if more than 1 occurence, remove that 
    int k = removeDuplicates(nums);

    //Print till k terms
    for(int i = 0; i<k ;i++){
        cout<<nums[i]<<"\t";
    }

    //Approach 2 : Constant space
    /*
    Keep a count variable for no. of duplicate elements.
    Shift the array towards left by 'count' index, make sure you leave 1 unique element.
    (If you are counting every element, then shift by count-1)
    After every shifting update the 'val' variable to new element.
    To get no. of unique elements, keep a counter initialized to 1(Initialized to 1 since this else condition runs when its finds 2nd unique element)
    Increase the counter by 1 every time you encounter a new element.
    */


    //Approach 3
    /*
    In this approach, keep track of unique elements, once you find unique element update it to the array
    */
    return 0;
}