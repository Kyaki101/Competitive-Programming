/*
*https://codeforces.com/contest/1993/problem/C
*/


#include <bits/stdc++.h>

#define int long long
typedef long long ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, k;
    cin >> n >> k;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int highest = a[n - 1] + (k - 1);
    int minMoment = highest;
    for(int i = 0; i < n - 1; i++){
        if(((highest - a[i]) / k) % 2 == 0){
            if(a[i] + ((highest - a[i]) / k) * k > a[n - 1]){
                a[n - 1] = a[i] + ((highest - a[i]) / k) * k;
            }
        } 

        else if(a[i] + ((highest - a[i]) / k) * k > a[n - 1]){
            highest = (a[i] + ((highest - a[i]) / k) * k) - 1;
        }
        else if (a[i] + ((highest - a[i]) / k) * k <= a[n - 1]){
            cout << "-1\n";
            return;
        }
    }
    cout << a[n - 1] << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}

