/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>

using namespace std;

bool isPalindrome2(string s){
        
        //Check for palindrome
        int start = 0;
        int end = s.length()-1;
        
        while(start<end){
            //If not alphanumeric at pointer "start", increment the pointer by 1
            while(!isalnum(s[start])){
                start++;
            }
            //If not alphanumeric at pointer "end", decrement by 1
            while(!isalnum(s[end])){
                end--;
            }
            cout<<s[start]<<"\t"<<s[end]<<endl;
            cout<<start<<"\t"<<end<<endl;
            //Make both the comparing characters to lower
            if((tolower(s[start])!=tolower(s[end]))){
                return false;
            }
            start++;
            end--;
        }
        //If it runs all through
        return true;
    }

using namespace std;

int main()
{
    string s= "A man, a plan, a canal: Panama";
    cout<<isPalindrome2(s);

    return 0;
}
