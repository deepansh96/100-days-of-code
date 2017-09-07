/**

Find nCr % p for given n, r and p;

Refer: http://www.geeksforgeeks.org/compute-ncr-p-set-1-introduction-and-dynamic-programming-solution/
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// forms the p of the problem statement
int M = pow(10, 9) + 7;

/** 
Compute (n_iCr_i % p) using Dynamic Programming, where n_i and r_i are
the same positioned digits in base p
**/
int ncrdp(int n, int r){
    vector<ll> C(r+1, 0);
    C[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=min(i, r); j>0; j--){
            C[j] = (C[j] + C[j-1]) % M;
        }
    }
    return C[r];
}


/**
Compute nCr % p
**/
int ncrlucas(int n, int r){
    if(r == 0) return 1;

    // get the digits in base p
    int ni = n % M, ri = r % M;

    // make the recursive call
    long long val = (ncrdp(ni, ri) * ncrlucas(n / M, r / M)) % M;
    return val;
}

int main() {
	int t, n, r;
	cin>>t;
	while(t--){
	    cin>>n>>r;
	    cout<<ncrlucas(n, r)<<endl;
	}
	return 0;
}