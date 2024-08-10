#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;
#define int long long

void sol(){
    int n, k, m;
    cin >> n >> k >> m;
    string words[n];
    int values[n];
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    int groups[k];
    for(int i = 0; i < k; i++) groups[i] = (1 << 30);
    map<string, int> hasher;
    int a;
    int b;
    for(int i = 0; i < k; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            b--;
            groups[i] = min(groups[i], values[b]);
            hasher[words[b]] = i;

        }
    }
    string ss;
    int res = 0;
    for(int i = 0; i < m; i++){
        cin >> ss;
        res += groups[hasher[ss]];
        
    }
    cout << res << endl;
    
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

