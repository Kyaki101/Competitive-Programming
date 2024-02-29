#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

ll arr[100001];




bool sol(){

    int n;
    cin >> n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    sort(arr, arr+n);
    if (arr[0] != arr[1]) return 1;
    for(int i = 1; i<n; ++i) if(arr[i]%arr[0]) return 1;
    return 0;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    cin >> t;
    while(t--) cout<<((sol())? "YES\n": "NO\n");
    return 0;
}