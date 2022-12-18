#include<iostream>
#include<unordered_map>
#include<vector>
//Count the frequency of array elements
//Using unordered map
using namespace std;

void count_no(int arr[]){

}

int main(){
    int arr[] = {1,2,3,4,5,3,1,5,7,1,23,6};


    //Approach 1
    //Using 2 for loops 
    //Using 1 vector to keep count of visited and keeping default value visited false
    //Change to true, when you have visited it
    cout<<"Approach 1 : "<<endl;
    
    int size =sizeof(arr)/sizeof(int);

    vector<int> visited(size,false);

    for(int i=0; i<size;i++){

        //Skip the iteration if the element is already visited
        if(visited[i]==true){
            continue;
        }

        int count = 1;
        for(int j=i+1 ; j<size ; j++){
            if(arr[i]==arr[j]){
                //And change visited to true
                visited[j] = true;
                count++;
            }
        }
        cout<<arr[i]<<" : "<<count<<endl;
    }

    cout<<"------------------------------------------"<<endl;

    //Approach 2
    //Using unordered map
    //stores in random order, stores unique key
    unordered_map<int,int> map;
    for(int i=0;i<size;i++){
        //Since random order and unique key, on second time accessing the key, the value gets updated
        map[arr[i]] = map[arr[i]]+1;
    }

    //Print the map
    for(auto it :map){
        cout<<it.first<<" : "<<it.second<<endl;
    }
    return 0;
}