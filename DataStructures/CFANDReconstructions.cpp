/*
*https://codeforces.com/contest/1991/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bool TEST(int num, int mask){
    return (num & (1 << mask));
}

ll findMSB(ll num){
    ll i = 0;
    ll msb = 0;
    while(i < 32){
        if(TEST(num, i)) msb = i;
        i++;
    }
    return msb;

}

ll SET(int num, int mask){
    return (num | (1 << mask));
}


void sol(){
    int n;
    cin >> n;
    vector<ll> a(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> a[i];
    }
    vector<ll> b(n);
    b[0] = a[0];
    for(int i = 0; i < n - 1; i++){
        if(i == n - 2){
            if((a[i] & b[i]) == a[i]){
                b[i + 1] = a[i];
                for(int i = 0; i < n; i++){
                    cout << b[i] << " ";
                }
                cout << endl;
                return;
            } 
            else{
                cout << "-1\n";
                return;
            }
        }
        int j = 0;
        int end = findMSB(a[i + 1]);
        int candidate = a[i];
        if((candidate & b[i]) != candidate){
            cout << "-1\n";
            return;
        }
        while(j <= end){
            if((SET(candidate, j) & b[i]) == a[i] && TEST(a[i + 1], j)){
                candidate = SET(candidate, j);
            } 
            j++;
        }
        b[i + 1] = candidate;
    }
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

