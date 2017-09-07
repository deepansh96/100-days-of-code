/**

Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string if 
a rightmost substring can be written as sum of two substrings before it and same is recursively true for 
substrings before it.

3
12243660
1111112223
2368

1
1
0

12243660 -> 60 = 36 + 24, 36 = 24 + 12 (12 24 36 60)
1111112223 -> 223 = 111 + 112, 112 = 111 + 1 (1 111 112 223)
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
Check if there is any i such that s[i:st] + left = sum and 
the sum-string requirement is applicable recursively.

st -> start index
**/
bool check(string s, ll sum, ll left, int st){
    if(st < 0) return true;
    
    // val stores what is the current value and count stores the number of digits
    ll val = 0, count = 0;

    for(int i=st; i>=0; i--){
        int v = s[i] - '0';
        val = pow(10, count) * v + val;

        // if val + left exceeds sum, then we don't need to check further
        if(val + left > sum) return false;

        // else check if the sum-string property holds recursively
        if(val + left == sum && check(s, left, val, i-1)) return true;

        // increment the digit count if val + left < sum
        count++;
    }
    
    return false;
}

/**
Return 1 or 0 corresponding to whether the given string is sum-string or not.
**/
int solve(string s){
    int n = s.size();
    if(n <= 2) return 0;

    // val stores the value of the rightmost substring and count maintains the digit count
    ll val = 0, count=0;
    
    for(int i=n-1; i>1; i--){
        int v = s[i] - '0';
        val = pow(10, count) * v + val;

        // sval stores the value of the substring next to the rightmost substring and sc maintains its digit count
        ll sval = 0, sc = 0;

        for(int j=i-1; j > 0; j--){
            int sv = s[j] - '0';
            sval = pow(10, sc) * sv + sval;

            // if sval already exceeds val, then we don't need to check further
            if(sval > val) break;

            // sum-string condition satisfied
            if(check(s, val, sval, j-1)) return 1;
            sc++;
        }

        count++;
    }
    
    // sum-string not found
    return 0;
}

int main() {
	int t;
	string s;
	cin>>t;
	while(t--){
	    cin>>s;
	    cout<<solve(s)<<endl;
	}
	return 0;
}