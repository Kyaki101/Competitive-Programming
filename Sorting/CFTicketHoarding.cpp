/*
*https://codeforces.com/contest/1951/problem/C
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n, m, k;
    cin >> n >> m >> k; 
    vector<ll> sales(n);
    for(int i = 0; i < n; i++){
        cin >> sales[i];
    }
    ll acum = 0;
    ll pr = 0;
    sort(sales.begin(), sales.end());
    for(int i = 0; i < n; i++){
        if(k <= m){
            acum += (k) * (sales[i] + pr);
            cout << acum << endl;
            return;
        }
        acum += m * (sales[i] + pr);
        pr += m;
        k -= m;

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

