/** 

Find the euler totient function for a given integer n
Refer: http://www.geeksforgeeks.org/eulers-totient-function/
**/

#include <bits/stdc++.h>
using namespace std;

long long euler(long long n){
    if(n <= 2) return 1;
    if(n == 3) return 2;
    long long ans = n;
    for(int i=2; i*i<=n; i++){
        if(n % i != 0) continue;
        while(n % i == 0) n /= i;
        
        ans = (ans * (1.0 - 1.0/(float)i));
    }
    if(n > 1){
        ans *= (1.0 - 1.0/(float)n);
    }
    
    return ans;
    
}

int main() {
    long long t, n;
    cin>>t;
    while(t--){
        cin>>n;
        // marked.resize(n+1, 0);
        // init(n);
        
        float maxv = 0;
        long long v = -1;
        
        for(long long i=1; i<=n; i++){
            long long ev = euler(i);
            float val = (float) i/ev;
            if(val > maxv){
                maxv = val;
                v = i;
            }
        }
        cout<<v<<endl;
    }
	return 0;
}