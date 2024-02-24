/*
https://codeforces.com/gym/104990/problem/D
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int h, m, n;
    cin >> h >> m;
    cin >> n;
    int time = (h * 60) + m;
    
    vector<pair<int, int>> stamps(n);
    for(int i = 0; i < n; i++){
        int a;
        int b;
        cin >> a >> b;
        stamps[i].first = a;
        stamps[i].second = b;
    }
    ll cost = 0;
    for(int i = 0; i < n; i++){
        if(stamps[i].first >= time){
            cost += stamps[i].second * time;
            cout << cost << endl;
            return;
        }
        cost += stamps[i].first * stamps[i].second;
        time -= stamps[i].first;
    }

    cout << cost << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}