#include <bits/stdc++.h>
#include <climits>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    while(t--){

        cin>>n>>s;
        if(n > 1 && s[0] == s[1]){
            cout<<s[0]<<s[0]<<endl;
            continue;
        }

        stack<char> st; 
        char curr = s[0];

        for(int i = 0; s[i] && s[i] < curr; ++i){
           st.push(s[i]);
           cout<<s[i];
        }
        
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }

        cout<<endl;

    }return 0;

}

