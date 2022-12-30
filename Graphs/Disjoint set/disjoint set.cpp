#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Disjoint set
//Union by Rank or Union by Size both take O(4*alpha) which is almost O(1)

/*
In a given graph, if you want to check if 2 vertex/nodes belong to same connected component :
1. BRUTE FORCE : Apply DFS/BFS on 1 node, and check if it reaches node 2 : If yes, then belong to same component.
                 But this approach takes O(n)

2. Disjoint set : Disjoint set helps us to check if 2 vertex/nodes belong to same component in O(1) time (constant time).
                This is usually used in dynamic graphs (in which graph configuration changes at every instant).
*/

/*-------------------------------------------------------------------------------------------------------------------*/

class DisjointSet{
    vector<int> rank, parent, size;

public:
    //Constructor
    //Here n is the size of the graph
    //Assuming at start every node is unconnected (isolated vertex)
    DisjointSet(int n){
        //Default values for rank is 0
        //We used resize so that it also works for 1 based indexing
        rank.resize(n+1, 0);
        parent.resize(n+1);

        //Defualt values for size is 1 as at starting every node is isolated
        size.resize(n+1, 1);

        //Default values for parent array is the node itself
        for(int i=0; i<parent.size(); i++){
            parent[i] = i;
        }
    }

    
    //Find ultimate parent (the node which is parent of itself)

    /*
    //This is without path compression (takes logN)

    int findUParent(int node){
        //Check if it is ultimate parent
        if(node == parent[node]){
            return node;
        }

        //If it is not the ultimate parent 
        //Give a recursive call to find parent of current node's parent
        return findUParent(parent[node]);
    }
    */

    //Finding ultimate parent with path compression
    //In path compression, we connect each checked node to its ultimate parent node (to reduce O(logN) to O(1) in future iteration)
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        //If not the ultimate parent
        //Update each node's parent to its ultimate parent using backtracking
        return parent[node] = findUParent(parent[node]);
    }


    //BOTH Union by size and Union by Rank are of same Time complexity

    //Union By Size
    //Size refers to the no. of nodes connected to ultimate parent (including the ultimate parent)
    void UnionBySize(int u, int v){
        //Find the ultimate parent of node u and node v
        int ultP_u = findUParent(u);
        int ultP_v = findUParent(v);

        //If they have the same ultimate parent, no need to do anything(attach) as they are already in same component
        if(ultP_u == ultP_v){
            return;
        }

        //If the size of ultimate parent of v is greater than that of u
        if(size[ultP_v] > size[ultP_u]){
            //Always connect smaller one to bigger one
            parent[ultP_u] = ultP_v;

            //Since we connected the components, the size of ultimate parent of v will increase
            size[ultP_v] += size[ultP_u];
        }

        else{
            //This covers both case if size[ultP_v] <= size[ultP_u]
            /*
            In size[ultP_v] < size[ultP_u] : we connect the smaller ultimate parent(ultP_v) to bigger one(ultP_u)

            In size[ultP_v] == size[ultP_u] : we can connect to either one. To increase code quality -> do the above one. 
                                              (You can do either one)
            */
            
            parent[ultP_v] = ultP_u;        

            size[ultP_u] += size[ultP_v];
        }
    }



    //Union by Rank
    void UnionByRank(int u, int v){
        //find ultimate parent of node u and node v
        int ultP_u = findUParent(u);
        int ultP_v = findUParent(v);

        //If they have the same ultimate parent, no need to do anything(attach) as they are already in same component
        if(ultP_u == ultP_v){
            return;
        }

        //Now, find the ranks of the ultimate parents
        //and compare them

        //If rank of ultimate parent of u is greater than that of node v, the smaller ultimate parent gets attached to the 
        //bigger one
        if(rank[ultP_u] > rank[ultP_v]){
            //Attach ultP_v to ultP_u and ultP_u becomes the parent
            //Since, we are attaching smaller rank to bigger one, the rank doesn't changes
            parent[ultP_v] = ultP_u;
        }

        else if(rank[ultP_u] < rank[ultP_v]){
            parent[ultP_u] = ultP_v;
        }

        else{
            //If rank of both nodes ultimate parent are same
            //Then you can attach any one of them to other ultimate parent. 
            //This will increase the rank of the node to which it is being attached.
            parent[ultP_u] = ultP_v;

            rank[ultP_v]++;
        }
    }

};

/*-------------------------------------------------------------------------------------------------------------------*/

int main() {
    DisjointSet ds(7);
    //Dynamic graph as it is changing at each line
    ds.UnionBySize(1, 2); 
    ds.UnionBySize(2, 3); 
    ds.UnionBySize(4, 5); 
    ds.UnionBySize(6, 7); 
    ds.UnionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.UnionBySize(3, 7); 

    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}