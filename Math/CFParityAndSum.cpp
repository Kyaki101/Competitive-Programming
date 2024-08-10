/*
*https://codeforces.com/contest/1993/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    int odds = 0, evens = 0;
    int maxEven = 0;
    priority_queue<int> os;
    priority_queue<int, std::vector<int>, std::greater<int> > evs;
    vec nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(nums[i] & 1){
            odds ++;
            os.push(nums[i]);
        }
        else{
            maxEven = max(nums[i], maxEven);
            evens ++;
            evs.push(nums[i]);
        }
    }
 
    if(evens == 0 || odds == 0){
        cout << "0\n";
        return;
    }
    int res = 0;

    while(!evs.empty()){

        if(evs.top() > os.top()){
            cout << res + (evens - res) + 1 << endl;
            return;
        }
        else{
            os.push(evs.top() + os.top());
            evs.pop();
            res ++;
        }
    }
    cout << res << endl;

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

