/**

Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’ under modulo ‘m’.
Input:  a = 3, m = 11
Output: 4
Since (4*3) mod 11 = 1, 4 is modulo inverse of 3
One might think, 15 also as a valid output as "(15*3) mod 11" 
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not valid.

Refer: http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

**/

#include <bits/stdc++.h>
using namespace std;

int power(int x, int y, int m){
    if(y == 0) return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p)  % m;
    return (y%2 == 0? p: (p * x) % m);
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool prime(int n){
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0 || n == 1) return false;
    // cout<<n<<"-"<<endl;
    for(int i=5; i*i<=n; i+=6){
        if(n%i ==0 || n % (i+2) == 0) return false;
    }
    // cout<<n<<"-"<<endl;
    return true;
}

void extendedeuclid(int a, int m,int &x, int &y){
    if(a == 0){
        x = 0; y=1;
        return;
    }
    int x1, y1;
    extendedeuclid(m%a, a, x1, y1);
    x = y1 - floor((m/a)) * x1;
    y = x1;
    
}

int euclid(int a, int m){
    int x=-1, y=-1;
    extendedeuclid(a, m, x, y);
    return (x%m + m) % m;
}

int main() {
	int t, a, m;
	cin>>t;
	while(t--){
	    cin>>a>>m;
	    
	    int val = -1;
	   // cout<<prime(m)<<endl;
	   //cout<<euclid(m,a);
	    if(a == m){
	        
	    }else if(gcd(m, a) == 1){
	        val = euclid(a,m);
	    }else if(prime(m)){
	        val = power(a, m-2, m);
	    }
	    cout<<val<<endl;
	}
	return 0;
}