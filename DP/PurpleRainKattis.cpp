#include <bits/stdc++.h>

typedef std::vector<int> list;

void what(std::string word){
    int counter = 0;
    int max = 0;
    int min = 0;
    int a = 1;
    int b = 1;
    for(int i = 0; word[i]; i++){
        if(word[i] == 'B')counter ++;
        else counter --;
        if(counter > max){max = counter; a = i + 1;}
        if(counter < min){min = counter; b = i + 1;}
    }
    int primero = std::min(a, b);
    int segundo = std::max(a, b);
    if(primero != 1)std::cout << primero + 1 << " ";
    else std::cout << primero << " ";
    std::cout << segundo << std::endl;

}

int main(){
    std::string input;
    std::cin >> input;
    what(input);
}