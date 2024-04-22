/*
*https://codeforces.com/contest/1957/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


bool TEST(ll k, int msk){
    return k & (1LL << msk);
}

ll lastBit(ll k){
    int last = 0;
    for(int i = 0; i < 64; i++){
        if(TEST(k, i)){
            last = i;
        }
    }
    return last;
}

void sol(){
    ll n, k;
    cin >> n >> k;
    if(n == 1){
        cout << k << endl;
        return;
    }
    ll dense = 1 << (lastBit(k));
    cout << dense - 1 << ' ' << k - (dense - 1);
    ll left = n - 2;
    for(int i = 0; i < left; i++){
        cout << " 0";
    }
    cout << endl;
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

