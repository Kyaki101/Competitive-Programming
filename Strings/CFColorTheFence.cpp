/*
*https://codeforces.com/group/5GNF7zti59/contest/535722/problem/G
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int findMin(int * a){
    int mini = (1 << 30);
    int index = 0;
    for(int i = 1; i < 10; i ++){
        if(a[i] <= mini){
            mini = a[i];
            index = i;
        }
    }
    return index;
}

void sol(){
    int n;
    cin >> n;
    int a[10];
    for(int i = 1; i < 10; i++){
        cin >> a[i];
    }
    int mini = findMin(a);
    if(a[mini] > n){
        puts("-1");
        return;
    }
    string s = "";
    while(a[mini]<= n){
        s += (char)('0' + mini);
        n -= a[mini];
    }
    int j = 0;
    for(int i = 9; i > 0; i --){
        while(a[i] <= n + a[mini] && j < s.size()){
            s[j] = (char)('0' + i);
            n -= a[i] - a[mini];
            j ++;
        }

    }
    cout << s << endl;

    
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

