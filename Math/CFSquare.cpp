#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vector<pair<int, int>> coords;

void sol(){
    coords.assign(4, make_pair(0, 0));
    int x, y;
    for(int i = 0; i < 4; i++){
        cin >> x >> y;
        coords[i].first = x;
        coords[i].second = y;
    }
    for(int i = 1; i < 4; i++){
        if(coords[i].first == coords[0].first){
            cout << (abs(coords[0].second - coords[i].second) * abs(coords[0].second - coords[i].second)) << '\n';
            return;
        }
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