#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int start = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            start = i;
            break;
        }
    }
    vec b;
    int prev = 0;
    for(int i = start; i < n; i++){
        if(prev != 1 || a[i] == 0)b.push_back(a[i]);
        prev = a[i];
    }
    int origin = 0;
    int steps = 0;
    for(int i = 1; i < b.size(); i++){
        if(b[i] == 1) {
            steps += abs((i - 1) - origin);
            origin = i;
        }
    }
    cout << steps << endl;
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