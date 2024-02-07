#include <bits/stdc++.h>
using namespace std;

int t, n, q, arr[200001], r, m  ;
vector<int> Q;



int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 0;i<n; i++) cin>>arr[i];
        Q.assign(n, 0);

        for(int i = 1; i<n; i++) 
            if(arr[i] != arr[i-1]) Q[i] = Q[i-1]+1;
            else Q[i] = Q[i-1];


        cin>>q;
        while(q--){

            cin>>r>>m;

            int i = Q[r-1];

            int j = lower_bound(Q.begin(), Q.end(), i+1)-Q.begin();
            if(j == i || j >= m) cout<<"-1 -1\n";
            else cout<<r<<' '<<j+1<<'\n';

        }cout<<'\n';


    }return 0;

}