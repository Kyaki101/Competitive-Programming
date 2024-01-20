#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;
vec nums;
vec as;
vec des;
int q;

void genAs(){
    for(int i = 2; i < n; i++){
        if(abs(nums[i - 1] - nums[i]) < abs(nums[i - 2] - nums[i - 1])){
            as.push_back(as[i] + 1);
        }
        else{
            as.push_back(as[i] + abs(nums[i - 1] - nums[i]));
        }
    }
}
void genDes(){
    for(int i = n - 3; i >= 0; i--){
        if(abs(nums[i + 1] - nums[i]) < abs(nums[i + 2] - nums[i + 1])){
            des.push_back(des[des.size() - 1] + 1);
        }
        else{
            des.push_back(des[des.size() - 1] + abs(nums[i + 1] - nums[i]));
        }
    }
}

void sol(){
    cin >> n;
    nums.assign(n, 0);
    as.assign(2, 0);
    as.push_back(1);
    des.assign(1, 0);
    des.push_back(1);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    genAs();
    genDes();
    cin >> q;
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        if(a < b)cout << as[b] - as[a] << endl;
        else{
            a = n - a;
            b = n - b;
            cout << des[b] - des[a] << endl;
        }
    }
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