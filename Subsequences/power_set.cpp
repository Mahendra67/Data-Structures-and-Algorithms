#include<iostream>
#include<bits/stdc++.h>
//Print all subsequences using power set 
/*
https://www.youtube.com/watch?v=b7AYbpM5YrE

For n numbers, the possible no. of subsequences is 2^n.
Here, 0 is for notTake and 1 is for take.

Run a loop from 0 to (2^n - 1) which can also be written as (1<<n)-1.

1<<2
Before:     1
After : 1 0 0 which is nothing but 2^2
Hence, 2^n can be written as (1<<n)
*/
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------*/

vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}