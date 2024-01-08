#include <bits/stdc++.h>

using namespace std;

int n;

int k;

int goal;

int counter = 0;

std::vector<int> ar;

int main(){
    cin >> n >> k;
    ar.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        if(i == k -1)goal = ar[i];
    }
    for(int i = 0; i < n; i ++){
        if(ar[i] >= goal && ar[i]){
            counter ++; 
        }
    }
    cout << counter << '\n';
}