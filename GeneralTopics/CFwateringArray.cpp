#include <bits/stdc++.h>

typedef std::vector<int> list;

list array;
list ranges;
int d, n, k;

int score(){
    int c = 0;
    for(int i = 0; i < n; i ++){
        if(array[i] == (i + 1)) c++;
    }
    return c;
}

void mod(int day){
    int end = ranges[day % k];
    for(int i = 0; i < end; i++){
        array[i] ++;
    }
}

int bestDay(){
    int max = 0;
    int sc;
    for(int i = 0; i < d; i ++){
        if(i > 2 * n + 2) break;
        sc = score();
        max = std::max(max, sc + ((d - (i + 1)) / 2));
        mod(i);
    }
    return max;
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> n >> k >> d;
        array.assign(n, 0);
        ranges.assign(k, 0);
        for(int i = 0; i < n; i++){
            std::cin >> array[i];
        }
        for(int i = 0; i < k; i++){
            std::cin >> ranges[i];
        }
        std::cout << bestDay() << '\n';
    }
}