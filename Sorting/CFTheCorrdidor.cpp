#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
typedef std::pair<int , int> par;
using namespace std;

vector<pair<int, int>> traps;

ll n;

bool compFirst(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

void sol(){
    cin >> n;
    traps.assign(n, std::make_pair(0, 0));
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        traps[i].first = a;
        traps[i].second = b;

    }
    sort(traps.begin(), traps.end(), compFirst);
    int maximal = (1 << 30);
    for(int i = 0; i < n; i ++){
        if(traps[i].first <= maximal){
            maximal = min(maximal, traps[i].first + ((traps[i].second - 1)/2));
        }
    }
    cout << maximal << '\n';
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