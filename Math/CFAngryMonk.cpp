/*
*https://codeforces.com/contest/1992/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n, k;
    cin >> n >> k;
    vector<ll> pieces(k);
    for(int i = 0; i < k; i++){
        cin >>  pieces[i]; 
    }
    sort(pieces.begin(), pieces.end());
    ll counter = 0;
    for(int i = 0; i < k - 1; i++){
        if(pieces[i] != 1){
            counter += (pieces[i] - 1) + pieces[i];
        }

        else{
            counter += 1;
        }
        
    }
    cout << counter << endl;
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

