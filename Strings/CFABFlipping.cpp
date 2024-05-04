/*
*https://codeforces.com/problemset/problem/1896/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int aCount = 0;
    int bCount = 0;
    int tot = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B' && i == n - 1){
            bCount ++;
            tot += bCount + aCount - 1;
        }
        if(bCount && s[i] == 'A' && aCount){
            tot += bCount + aCount - 1;
            bCount = 0;
            aCount = 2;
        }
        else if(s[i] == 'A') aCount ++;
        else if (aCount) bCount ++;
    }
    cout << tot << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}

