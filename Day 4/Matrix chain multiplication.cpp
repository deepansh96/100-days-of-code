/**
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

Example:
 if you had four matrices A, B, C, and D, you would have:

    (ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.

For example:

A: 10 × 30 matrix
B : 30 × 5 matrix
C : 5 × 60 matrix
Then,
     (AB)C = (10×30×5) + (10×5×60) 
           = 1500 + 3000 
           = 4500 operations
     A(BC) = (30×5×60) + (10×30×60) 
           = 9000 + 18000 
           = 27000 operations.
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	//code
	vector<vector<ll> > dp;
	vector<int> val;
	int t, n;
	cin>>t;
	while(t--){
	    cin>>n;
	    val.clear();
	    dp.clear();
	    dp.resize(n, vector<ll>(n,0));
	    val.resize(n);
	    for(int i=0; i<n; i++) cin>>val[i];
	    for(int i=1; i<n-1; i++){
	        dp[i][i]=0;
	        dp[i][i+1] = (long long) val[i-1] * val[i] * val[i+1];
	    }
	    
	    dp[n-1][n-1] = 0;
	    
	    for(int k=3; k<n; k++){
	        for(int i=1; i<=n-k; i++){
	            int j=i+k-1;
	            dp[i][j] = INT_MAX;
	            for(int q=i; q<j; q++){
	                ll val1 = (long long)val[i-1]  * val[q] * val[j] + dp[i][q] + dp[q+1][j];
	                dp[i][j] = min(val1, dp[i][j]);
	            }
	        }
	    }
	    
	    cout<<dp[1][n-1]<<endl;
	}
	return 0;
}