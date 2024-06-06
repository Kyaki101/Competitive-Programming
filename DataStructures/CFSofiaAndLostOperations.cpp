/*
*https://codeforces.com/contest/1980/problem/C
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    vec b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int k;
    cin >> k;
    vec d(k);
    for(int i = 0; i < k; i++){
        cin >> d[i];
    }
    reverse(d.begin(), d.end());
    set<int> prelim;
    for(int i = 0; i < n; i++){
        prelim.insert(b[i]);
    }
    if(prelim.find(d[0]) == prelim.end()){
        cout << "NO\n";
        return;
    }
    map<int, int> sym;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(sym.find(b[i]) == sym.end()) sym[b[i]] = 1;
            else sym[b[i]] ++;
        }
    }
    for(int i = 0; i < k; i++){
        if(sym.find(d[i])!= sym.end() && sym[d[i]] != 0){
            sym[d[i]] --;
        }
    }
    for(auto i : sym){
        if(i.second){
            cout << "NO\n";
            return;
        } 
    }
    cout << "YES\n";
    
    
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

