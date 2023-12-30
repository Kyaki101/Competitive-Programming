#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;

int n;
ll a = 0;
ll b = 0;
vec marbsA;
vec marbsB;

int findMin(vec & marbles){
    int min = (1 << 30);
    int index;
    for(int i = 0; i < n; i++){
        if(marbles[i] < min && marbsA[i] > 0 && marbsB[i] > 0){min = marbles[i]; index = i;}
    }
    return index;
}

int findMax(vec & marbles){
    int max = -(1 << 30);
    int index;
    for(int i = 0; i < n; i++){
        if(marbles[i] > max){max = marbles[i]; index = i;}
    }
    return index;
}

bool follow(){
    for(int i = 0; i < n; i++){
        if(marbsA[i] > 0 && marbsB[i] > 0) return true;
    }
    return false;
}


int play(){
    int turn = 0;
    while(follow()){
        if((turn % 2) == 0){
            int rm = findMin(marbsB);
            a --;
            marbsA[rm] --;
            b -= marbsB[rm];
            marbsB[rm] = 0;
        }
        else{
            int rm = findMin(marbsA);
            b --;
            marbsB[rm] --;
            a -= marbsA[rm];
            marbsA[rm] = 0;
        }
        turn ++;
    }
    return a - b;
}


int main(){
    int t;
    std::cin >> t;
    int temp;
    while(t--){
        std::cin >> n;
        marbsA.assign(n, 0);
        marbsB.assign(n, 0);
        for(int i = 0; i < n; i ++){
            std::cin >> temp;
            marbsA[i] = temp;
            a += temp;
        }
        for(int i = 0; i < n; i ++){
            std::cin >> temp;
            marbsB[i] = temp;
            b += temp;
        }
        std::cout << play() << '\n';
    }

    return 0;
}