#include<iostream>
#include<bits/stdc++.h>
//Print all subsequences using recursion

//Time complexity is 2^n * n
//Since for every index you have 2 options:take or not take
//*n for printing every subsequence
using namespace std;

void print_array(vector<int> v1){
    for(int i=0 ; i<v1.size() ; i++){
        cout<<v1[i]<<" ";
    }
    if(v1.size()==0){
        cout<<"Empty set";
    }
    cout<<endl;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

void subsequence(int i,vector<int>& temp,int size,vector<int> v){
    //Base case
    if(i == size){
        print_array(temp);
        return;
    }

    //Take case
    temp.push_back(v[i]);

    subsequence(i+1 , temp, size, v);

    //NOT Take case
    temp.pop_back();

    subsequence(i+1, temp, size, v);

}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    //Original vector
    vector<int> v = {2,4,8};

    vector<int> temp;
    int i=0;
    int size_original = v.size();
    
    subsequence(i,temp,size_original,v);
    return 0;
}