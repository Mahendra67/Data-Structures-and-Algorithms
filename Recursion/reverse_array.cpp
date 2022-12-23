#include<iostream>
#include<bits/stdc++.h>
//Reverse an array or vector using recursion
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Using 2 pointers
void reverse1(vector<int>& v1,int l, int r){
    if(l>=r){
        return;
    }
    swap(v1[l],v1[r]);
    reverse1(v1,l+1,r-1);
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

//Using 1 pointer 
void reverse2(vector<int>& v1,int i){
    if(i >= v1.size()/2){
        return;
    }
    swap(v1[i],v1[v1.size()-1-i]);
    reverse2(v1,i+1);
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

void print_array(vector<int> v){
    for(auto it:v){
        cout<<it<<" ";
    }
    return;
}

int main(){
    vector<int> v1 = {3,1,4,2,6,7,9};
    int l = 0;
    int r = v1.size()-1;
    reverse1(v1,l,r);

    //Print the array
    print_array(v1);
    cout<<endl;

    //Using 1 pointer only 
    reverse2(v1,0);

    //Print the array again
    print_array(v1);

    return 0;
}