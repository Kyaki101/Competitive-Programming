//Given a sset of objcets which have both a value and a weight (v_i, w_i) what is the maximium value
//we can obtain by selecting a subset of heses objects such that the sum of the weights does not 
//exceed a certain capacity

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vec;

vec weights, values;

vector<vec> memo;

typedef long long int ll;
typedef vector<int> vec;

void knapsack(int n, int c){

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= c; j++){
            if(j - weights[i - 1] < 0){
                memo[i][j] = memo[i - 1][j];
            }
            else{
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
}


int main(){
    int n, c;
    cin >> n >> c;
    weights.assign(n, 0);
    values.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> values[i];
        cin >> weights[i];
    }
    memo.assign(n + 1, vector<int>(c + 1, 0));
    knapsack(n, c);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= c; j++){
            cout << memo[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

