#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;
#define INF (1 << 30);

vec nums;
int n;

void sol(){
    cin >> n;
    nums.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int x = INF;
    int y = INF;
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(x > y){
            swap(x, y);
        }
        if(nums[i] <= x){
            x = nums[i];
        }
        else if(nums[i] <= y){
            y = nums[i];
        }
        else{
            x = nums[i];
            counter ++;
        }
    }
    cout << counter << '\n';
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