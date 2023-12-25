//La complejodad de este algoritmo es $O(n^2)$
//https://open.kattis.com/problems/sellingspatulas

#include <bits/stdc++.h>
typedef std::vector<long double> list;

int n;
long double p, COST = 0.08;

std::vector<int> times;
std::vector<long double> incomes;

void queries(){
    std::vector<long double> ac; 
    ac.push_back(0.0);
    for(int i = 0; i<n; i++) 
        ac.push_back(ac.back() + incomes[i]);
    long double max = 0.0;
    int x, y;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            long double curr = ac[i] - ac[j-1] - (times[i-1] - times[j-1] + 1)*COST;
            if(max < curr){
                max = curr;
                x = times[i-1]; 
                y = times[j-1];
            }else if(max == curr && (((times[i-1] - times[j-1]) < (x - y)) || (((times[i-1] - times[j-1]) == (x - y)) && (y > times[j-1])))){
                x = times[i-1];
                y = times[j-1];
            }
            
        }

    }printf((!max)? "no profit\n": "%.2Lf %d %d\n", max, y, x);


}




int main(){
   std::ios::sync_with_stdio(false);
    std::cin>>n;
    while(n){

        times.assign(n, 0); incomes.assign(n, 0.0);
        for(int i = 0; i<n; i++){


            std::cin>>times[i];
            std::cin>>incomes[i];

        }
        queries();
        std::cin>>n;

    }

    return 0;
}