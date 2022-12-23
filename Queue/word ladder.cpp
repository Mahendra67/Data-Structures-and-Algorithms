#include<iostream>
#include<bits/stdc++.h>
// Word Ladder LeetCode 127
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList 
is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words 
in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/
using namespace std;


/*----------------------------------------------------------------------------------------------------------------------------------*/
//BRUTE FORCE APPROACH : BFS
class Solution {
public:
    /*
    Approach: 
    Take the word and change each of its letters from a-z, and check if it exists in the
    vector given. If it is given, remove that word from the vector to avoid infinte loop.
    eg. hat was transformed to cat.
        But for "cat" -> 'c' can be changed to 'h' as h comes between a-z and exists in vector.
        Hence, once we find a word, we need to remove it from the vector.
        
    Also, at every transformation, we are checking if that word exits in vector -> takes
    O(n) to search. Instead of this, we can store each word of the vector in unordered_set
    to reduce TC to almost O(1).
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Queue stores the current string and the steps it took to reach that word
        //pair<string,steps>
        queue<pair<string,int>> q;
        
        //Add all the vector<string> elements to unordered set
        unordered_set<string> s(wordList.begin(), wordList.end());
        
        //At step 1, push the beginWord into the queue
        q.push({beginWord, 1});
        //Now, remove the beginWord from the set
        s.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            //Check if the 'word' is equal to endWord (word we are looking for)
            /*Since it is BFS traversal, it will visit all possibilities in step:N
            before moving to possibilities in step:N+1.
            Hence 'steps' will have the minimum steps*/
            if(word == endWord){
                return steps;
            }
            
            //Run a loop for all words of 'word'
            for(int i=0; i<word.size(); i++){
                //This is to keep track of original letter
                char original = word[i];
                for(char c='a'; c<='z'; c++){
                    //replace the original letter by c
                    word[i] = c;
                    
                    //Check if it exist in set
                    if(s.find(word) != s.end()){
                        //If it exists, remove from set & push to queue, with steps increased
                        s.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                //After the inner loop completes, the word[i] becomes z.
                //To get back to original word, keep track of the original letter.
                word[i] = original;
            }
        }
        
        //If it reaches here, then no such sequence exits
        return 0;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    return 0;
}