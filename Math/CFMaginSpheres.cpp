#include <bits/stdc++.h>

#define int long long
using namespace std;
int a, b, c, n, m, w;

signed  main(){
    cin>>a>>b>>c>>n>>m>>w;
    int total = (a + b + c) - (n + m + w);
    if((n & 1) != (a & 1) && a > n) total --;
    if((m & 1) != (b & 1) && b > m) total --;
    if((w & 1) != (c & 1) && c > w) total --;
    if(total < 0){
        puts("NO");
        return 0;
    }
    if(n > a){
        if(n - a > total){
            puts("NO");
            return 0;
        }
        total -= n - a;
    }
    if(m > b){
        if(m - b > total){
            puts("NO");
            return 0;
        }
        total -= m - b;
    }
    if(w > c){
        if(w - c > total){
            puts("NO");
            return 0;
        }
        total -= c - w;
    }
    cout << "YES" << endl;
}

