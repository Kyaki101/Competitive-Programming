/*
https://codeforces.com/problemset/problem/1921/D
*/

#include <bits/stdc++.h>


typedef unsigned long long int ll;
typedef std::vector<int> vec;
using namespace std;

vec vecA;
vec vecB;

void sol(){
    int n, m;
    cin >> n >> m;
    vecA.assign(n, 0);
    vecB.assign(m, 0);
    for(int i = 0 ; i < n; i++){
        cin >> vecA[i];
    }
    for(int i = 0 ; i < m; i++){
        cin >> vecB[i];
    }
    int count = 0;
    ll difs = 0;
    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());

    int i = 0;
    int j = m - 1;
    bool flag = false;
    while(count < n){
        if(abs(vecA[i] - vecB[j]) < abs(vecA[i] - vecB[(n - 1) - i]) && (n - 1) - i <= j && !flag){
            j = 0;
            i = n - 1;
            flag = true;
        }
        difs += abs(vecA[i] - vecB[j]);
        if(flag){
            j ++;
            i --;
        }
        else{
            j--;
            i ++;
        }
        count ++;
    }
    cout << difs << endl;;

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