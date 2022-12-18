#include<iostream>
#include<unordered_map>
//Find the highest and lowest frequency of an element in an array

using namespace std;

int main(){
    int arr[] = {1,2,4,3,1,4,1,3,4,6,4,1,0,9,0,0,0};

    //Approach 1 
    //Using unordered map
    //Count the elements in an unordered map, and display the highest element (if occurence is same, display the smallest element)
    unordered_map<int,int> mpp;
    int size = sizeof(arr)/sizeof(int);
    //Counting
    for(int i=0;i<size ;i++){
        mpp[arr[i]]++;
    }
    //Display the highest and lowest element
    int max_occurence = mpp[arr[0]];
    int max_number = arr[0];
    for(auto it:mpp){
        if(it.second>max_occurence){
            max_occurence = it.second;
            max_number = it.first; 
        }
        else if(it.second == max_occurence){
            //Give the preference to smaller number
            if(it.first < max_number){
                max_number = it.first;
            }
        }
    }

    cout<<"Max frequency element is : "<<max_number<<" : "<<max_occurence<<endl;

    //Display the lowest element, if same frequency display the largest number
    int least_occurence = mpp[arr[0]];
    int least_number = arr[0];
    for(auto it: mpp){
        if(it.second<least_occurence){
            least_occurence = it.second;
            least_number = it.first;
        }
        else if(it.second == least_occurence){
            if(it.first > least_number){
                least_number  = it.first;
            }
        }
    }

    cout<<"Minimum frequncy element is : "<<least_number<<" : "<<least_occurence<<endl;

    return 0;
}