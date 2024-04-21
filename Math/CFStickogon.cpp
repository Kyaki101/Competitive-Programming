/*
*https://codeforces.com/contest/1957/problem/A
*/ 


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    unordered_map<int, int> w;
    int k;
    int count = 0;
    for(int i = 0; i < n; i++){
        cin >> k;
        if(w.find(k) == w.end()){
            w[k] = 1;
        }
        else{
            w[k] ++;
            if(w[k] == 3){
                count ++;
                w[k] = 0;
            }
        }
    }
    cout << count << endl;
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

