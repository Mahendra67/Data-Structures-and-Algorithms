#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pb push_back
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define all(x) (x).begin(),(x).end()
#define input(a) for(auto& it: (a)) cin>>it;
#define pb push_back


/*---------------Custom Hash for unordered map (to avoid blowing up)----------------*/

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//unordered_map<int,int,custom_hash> mpp;

/*--------------------------------------------------------------------------------*/

/*----------------------------------DEBUG--------------------------------------*/

//If online_judge is not defined -> dont use it, else gives TLE
#ifndef ONLINE_JUDGE
template<class T> void _print(T& x){
	cerr<<x<<" ";
	return;
}

void _print(pair<int,int>& x){
	cerr<<endl;
	cerr<<"first :"<<x.first<<" second :"<<x.second<<" ";
	return;
}

template<class T> void _print(vector<T>& x){
	for(ll i=0; i<x.size(); i++){
		_print(x[i]);
	}
	return;
}

template<class T> void _print(vector<vector<T>>& x){
	cerr<<endl;
	for(auto& it: x){
		_print(it);
		cerr<<endl;
	}
	return;
}

template<class T, class U> void _print(unordered_map<T,U>& x){
	cerr<<endl;
	for(auto& it: x){
		cerr<<"key: "<<it.first<<" val :"<<it.second<<endl;
	}
	cerr<<"mpp ended ------------------"<<endl;
	return;
}

template<class T> void _print(unordered_set<T>& x){
	cerr<<endl;
	for(auto& it: x){
		cerr<<it<<" ";
	}
	cerr<<endl<<"set ended ----------------------"<<endl;
	return;
}

#define debug(x) cerr<<#x<<" : "; _print(x); cerr<<endl;

#else
#define debug(x)
#endif

/*----------------------------------DEBUG--------------------------------------*/

//For upsolving
int testNo, currTestNo;

class DisjointSet{
public:
	vector<int> parent, size;
	DisjointSet(int n){
		size.resize(n+1, 1);
		parent.resize(n+1);
		for(int i=0; i<n+1; i++){
			parent[i] = i;
		}
	}

	int findUParent(int u){
		if(parent[u] == u){
			return u;
		}

		return parent[u] = findUParent(parent[u]);
	}

	void unionSize(int u, int v){
		int ultU = findUParent(u);
		int ultV = findUParent(v);

		if(ultU == ultV) return;
		if(size[ultU] > size[ultV]){
			parent[ultV] = ultU;
			size[ultU] += size[ultV];
		}else{
			parent[ultU] = ultV;
			size[ultV] += size[ultU];
		}
		return;
	}
};

//ncr, binary expo, log wale functions

//Sieve n*log(log(n))
vector<bool> primes;
vector<int> highestPrime, lowestPrime;
void sieve(int n){
	primes.resize(n+1, 1);

	// highestPrime.resize(n+1, 0);
	// lowestPrime.resize(n+1, 0);

	primes[0] = primes[1] = false;
	for(int i=2; i*i <= n; i++){
		if(primes[i]){
			// lowestPrime[i] = highestPrime[i] = i;
			for(int j=i*i; j<=n; j+=i){
				primes[j] = 0;

				// highestPrime[j] = i;

				// if(lowestPrime[j] == 0){
				// 	lowestPrime[j] = i;
				// }
			}
		}
	}

	return;
}



//Segmented sieve (r-l)<=1e6   -> l, r can be upto 1e11
//Assuming l and r are inclusive
vector<int> SegSieve(int l, int r){
	//First create list of primes upto r
	vector<int> customPrime;
	int sqrtN = sqrt(r);
	sieve(sqrtN);
	for(int i=2; i<=sqrtN; i++){
		if(primes[i]){
			customPrime.push_back(i);
		}
	}

	//Only create array for the custom array you want
	vector<int> SegPrime(r-l+1, 1);
	
	//Mark multiples of primes found in sqrt(r);
	for(auto& it: customPrime){
		int firstMultiple = ceil((double)l/it) * it;

		for(int j=max(firstMultiple, it*it); j<=r; j+=it){
			SegPrime[j-l] = 0; 
		}
	}

	vector<int> primesInRange;
	for(int i=0; i<SegPrime.size(); i++){
		if(SegPrime[i]){
			primesInRange.push_back(i+l);
		}
	}

	return primesInRange;
}


//Binary expo
int pow(int n, int p){
	if(p == 0){
		return 1;
	}

	int ans = 1;
	if(p%2 == 0){
		ans = pow(n, p/2) * pow(n, p/2);
	}else{
		ans = n * pow(n, p/2) * pow(n, p/2);
	}

	return ans;
}


//const int mod = 1e9+7 is faster than int mod=1e9+7
/*---------------------------------Sol starts here------------------------------------*/

void solve(){
	
	return;
}

 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif

    cin>>testNo;

    for(currTestNo=1; currTestNo<=testNo; currTestNo++){
    	solve();
    }

    // solve();

    // for(int i=1; i<=n; i++){
    // 	cout<<"Case #"<<i<<": ";
    // 	solve();
    // }

    return 0;
}
