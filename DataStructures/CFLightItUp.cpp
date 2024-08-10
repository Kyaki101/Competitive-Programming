#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vector<int> ac(vector<int> & a, bool on){
    vec acum(1, 0);
    if(on){
        for(int i = 1; i < a.size(); i++){
            if(i & 1){
                acum.push_back(acum[i - 1] + (a[i] - a[i - 1]));
            }
            else acum.push_back(acum[i - 1]);
        }
        return acum;
    }
    else{
        for(int i = 1; i < a.size(); i++){
            if(!(i & 1)){
                acum.push_back(acum[i - 1] + (a[i] - a[i - 1]));
            }
            else acum.push_back(acum[i - 1]);
        }
        return acum;
    }

}

void sol(){
    int n, m;    
    cin >> n >> m;
    vec a(n);
    a.push_back(0);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    a.push_back(m);
    int down = 0, up = 0;
    for(int i = 1; i < n + 1; i++){
        if(i & 1)down += a[i] - a[i - 1];
        else up += a[i] - a[i - 1];
    } 
    vec on = ac(a, true);
    vec off = ac(a, false);
    int fin = n + 1;

    int maxVal = 0;
    int delta = 0;
    for(int i = 1; i < on.size(); i++){
        if(on[fin] - on[i] < off[fin] - off[i] && (off[fin] - off[i]) - (on[fin] - on[i]) > 1){
            if((off[fin] - off[i]) - (on[fin] - on[i]) > delta){
                delta = (off[fin] - off[i]) - (on[fin] - on[i]);
                maxVal = on[i] + ((off[fin] - off[i]) - 1);
            }
        }
    }
    cout << std::max(on[on.size() - 1], maxVal) << endl;





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

