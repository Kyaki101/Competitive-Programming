#include <bits/stdc++.h>

typedef std::vector<int> list;
typedef std::vector<list> mat;
typedef std::vector<std::vector<char>> map;
std::set<std::pair<int, int>> memo;

map word(3, std::vector<char>(3, ' '));

std::set<std::string> words;


int moves[8][2] = {{-1, 0}, {-1, -1}, {0,-1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};


std::string comp(std::string a, std::string b){
    for(int i = 0; i < 3; i++){
        if((int)a[i] < (int)b[i]){
            return a;
        }
    }
    return b;
}

bool isAdj(int i, int j, int k, int u){
    for(int q = 0; q < 8; q++){
        if(i + moves[q][0] == k && j + moves[q][1] == u)return true;
    }
    return false;
}


void sol(){
    std::pair<int, int> first;
    std::pair<int, int> second;
    std::pair<int, int> third;
    std::string temp = "";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int u = 0; u < 3; u++){
                    for(int w = 0; w < 3; w++){
                        for(int e = 0; e < 3; e++){
                            first = std::make_pair(i, j);
                            second = std::make_pair(k, u);
                            third = std::make_pair(w, e);
                            if(first != second && first != third && second != third && isAdj(i, j, k, u) && isAdj(k, u, w, e)){temp += word[i][j]; 
                                temp += word[k][u]; 
                                temp+= word[w][e]; 
                                words.insert(temp);
                                temp = "";
                                }
                        }
                    }
                }
            }
        }
    }
    std::string min = "zzz";
    for(std::string i : words){
        min = comp(min, i);
    }
    std::cout << min << std::endl;
}

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> word[i][j];
        }
    }
    sol();

}