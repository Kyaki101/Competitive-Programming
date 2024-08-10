#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll meals[3];
    cin >> meals[0] >> meals[1] >> meals[2];
    sort(meals, meals + 3);
    reverse(meals, meals + 3);
    ll res = 0;
    if(meals[0] == 0){
        cout << 0 << endl;
        return;
    }
    if(meals[0] != meals[1]) res += (meals[0] - 1) - meals[1];
    if(meals[0] != meals[2]) res += (meals[0] - 1) - meals[2];
    cout << res << endl;

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

