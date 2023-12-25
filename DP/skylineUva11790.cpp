//La complejidad de este algoritmo es O(n);
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2890

#include <bits/stdc++.h>
typedef std::vector<int> list;


list heights;
list widths;
int buildings;

int maxw(list & sql){
    int max = 0;
    int index = 0;
    for(int i = 0; i < buildings; i ++){
        if (sql[i] > max){
            max = sql[i];
            index = i;
        }
    }
    return index;
}

int maxcs(){
    list tam(buildings, 0);
    bool flag;
    for(int i = 0; i < buildings; i++){
        tam[i] += widths[i];
        flag = false;
        for(int j = 0; j < i; j++){
            if(heights[j] < heights[i] && widths[i] + tam[j] > tam[i]){
                tam[i] = widths[i] + tam[j];
            }

        }
    }
    int max = maxw(tam);
    int front = max;
    return tam[max];
}
int mincs(){
    list tam(buildings, 0);
    bool flag;
    for(int i = 0; i < buildings; i++){
        tam[i] += widths[i];
        flag = false;
        for(int j = 0; j < i; j++){
            if(heights[j] > heights[i] && widths[i] + tam[j] > tam[i]){
                tam[i] = widths[i] + tam[j];
            }

        }
    }
    int max = maxw(tam);
    int front = max;
    return tam[max];
}

int main(){
    int cases;
    std::cin >> cases;
    for(int i = 0 ; i< cases; i ++){
        std::cin >> buildings;
        std::vector<int> memo(buildings, 1);
        heights.assign(buildings, 0);
        widths.assign(buildings, 0);

        for(int i = 0; i < buildings; i++){
            std::cin >> heights[i];
        }
        for(int i = 0; i < buildings; i++){
            std::cin >> widths[i];
        }
        int max = maxcs();
        int min = mincs();
        if(min > max){
            std::cout << "Case " << i + 1 << ". Decreasing (" << min << "). Increasing (" << max << ").\n";
        }
        else std::cout << "Case " << i + 1 << ". Increasing (" << max << "). Decreasing (" << min << ").\n";
    }

    return 0;
}