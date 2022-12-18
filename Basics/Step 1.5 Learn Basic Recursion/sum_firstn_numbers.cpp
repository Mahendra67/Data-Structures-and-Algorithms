#include<iostream>

using namespace std;

int sum(int n){
    //Base Class
    if(n==0){
        return 0;
    }
    return n + sum(n-1);
}


int main(){
    int n = 6;
    cout<<sum(n)<<endl;

    //Appraoch 2
    int res = n*(n+1)/2 ; 
    cout<<"Approach 2 : "<<res;
    return 0;
}