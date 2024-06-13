#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int maxi = 0;
    ll sum = 0;
    int cont = 0;
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] > maxi){
            sum += maxi;
            maxi = a[i];
        }
        else{
            sum += a[i];
        }
        if(maxi - sum == 0){
            cont ++;
        }
    }
    cout << cont << endl;

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

