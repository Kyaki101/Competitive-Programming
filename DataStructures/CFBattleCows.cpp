/*
*https://codeforces.com/contest/1951/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<ll> vec;
using namespace std;

void sol(){
    int n, k;
    cin >> n >> k;
    vec cows(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }
    k--;

    int greater = -1;
    for(int i = 0; i < n; i++){
        if(cows[i] > cows[k]){
            greater = i; break;
        }
    }
    if(greater == -1){
        cout << n - 1 << '\n';
        return;
    }
    if(greater > k){
        cout << greater - 1 << endl;
        return;
    }
    long long int bigger = 0;
    long long int start = 0;
    for(int i = 1; i < k; i++){
        if(cows[k] > cows[i])start ++;
        else break;
    }
    for(int i = greater + 1; i < k; i++){
        if(cows[k] > cows[i])bigger++;
        else break;
    }
    if(greater > 0)bigger ++;
    cout << max(bigger, start) << endl;
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

