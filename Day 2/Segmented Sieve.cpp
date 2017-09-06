/**Given two numbers L and R (inclusive) find the product of primes within this range. 
Print the product modulo 10^9+7. If there are no primes in that range you must print 1.

Refer: http://www.geeksforgeeks.org/segmented-sieve/
**/

#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r){
    int sq = sqrt(r);
    if(sq * sq != r) sq++;
    
    vector<bool> mark(sq+1, true);
    vector<int> prime;

    for(int i=2; i*i<=sq; i++){
        if(mark[i]){
            for(int j=i*i; j<=sq; j=j+i){
                mark[j] = false;
            }
        }
    }
    int M = pow(10, 9) + 7;
    long long ans = 1;
    for(int i=2; i<=sq; i++){
        if(mark[i]) {
            prime.push_back(i);
            
            // cout<<i<<endl;
            ans = (ans * i) % M;
        }
    }

    int n=r/sq;
    if(n * sq < r) n++;
    for(int i=2; i<=n; i++){
        fill(mark.begin(), mark.end(), true);
        int s = (i-1) * sq+1;
        int e = i<n? i * sq : min(r, i*sq);
        for(int j=0; j<prime.size(); j++){
            int p = prime[j];
            // int divi = s / p;
            int k;
            if(s % p == 0) k = s;
            else k = p * (s/p + 1);
            for(; k<=e; k=k+p){
                if(k < s) continue;
                mark[k] = false;
            }
        }
        
        for(int j=s; j<=e; j++){
            if(mark[j]){
                // cout<<j<<endl;
                ans = (ans * j) % M;
            }
        }
    }
    
    return ans;
    
}

int main() {
	int t, l, r;
	cin>>t;
	while(t--){
	    cin>>l>>r;
	    cout<<solve(l ,r)<<endl;
	}
	return 0;
}