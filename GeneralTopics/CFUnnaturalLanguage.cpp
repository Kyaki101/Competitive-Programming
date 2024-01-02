#include <bits/stdc++.h>

typedef std::string str;
typedef std::set<char> tree;

tree vowels = {'a', 'e'};
tree consonants = {'b', 'c', 'd'};

str word;
long long int n;

void addSyl(str & wrd, int begin, int end){
    for(int i = begin; i < end; i++){
        wrd += word[i];
    }
    if(end != n)wrd += '.';
}

void sol(){
    int i = 0;
    str res = "";
    while(i < n - 3){
        auto sec = vowels.find(word[i + 3]);
        if(sec == vowels.end()){
            addSyl(res, i, i + 3); i+= 3;
        }
        else {addSyl(res, i, i + 2); i += 2;}
    }
    addSyl(res, i, n);
    std::cout << res << '\n';
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> n;
        std::cin >> word;
        sol();
    }


    return 0;
}