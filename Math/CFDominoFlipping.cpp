#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int n, m;
    cin >> n >> m;
    int mayor = max(n, m);
    int menor = min(n, m);
    int res = (mayor/2) * (menor) + (menor/2) * (mayor % 2);
    cout << res << endl;


    return 0;
}