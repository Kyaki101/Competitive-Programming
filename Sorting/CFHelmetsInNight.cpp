#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<ll> vec;
using namespace std;

ll n, p;

vector<pair<ll, ll>> popu;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    return a.second < b.second;
}

void sol(){
    cin >> n >> p;
    popu.assign(n, make_pair(0, 0));
    ll a;
    for(ll i = 0; i < n; i++){
        cin >> a;
        popu[i].first = a;
    }
    for(ll i = 0; i < n; i++){
        cin >> a;
        popu[i].second = a;
    }
    sort(popu.begin(), popu.end(), comp);
    ll i = 0;
    ll cost = p;
    ll left = n - 1;
    while(i < n && popu[i].second < p && left > 0){
        if(popu[i].first > left){
            cost += popu[i].second * left;
            left = 0;
        }
        else{
            left -= popu[i].first;
            cost += popu[i].first * popu[i].second;
        }
        i++;
    }
    cost += left * p;
    cout << cost << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    ll t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}