#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    ll n, m, a;
    cin >> n >> m >> a;
    ll x = 0;
    if(n % a)x += 1;
    x += n / a;
    ll y = 0;
    if(m % a)y += 1;
    y += m / a;
    cout << x * y << endl;


    return 0;
}