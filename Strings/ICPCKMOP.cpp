#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'Y'};

bool isVowel(char c){
    for(int i = 0; i < 6; i++){
        if(c == vowels[i]){
            return true;
        }
    }
    return false;
}

void fill(vector<string> & v, int n){
    for(int i = 0; i < n; i++){
        if(v[i].size() == 1){
            v[i] += "RR";
        }
        else if(v[i].size() == 2){
            v[i] += "R";
        }
    }
}

void sol(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    fill(words, n);
    int i = 0;
    int counter = 0;
    while(i < n){

        if(i == n - 2){
            counter += 2;
            i ++; i++;
        }
        else if(i == n - 1){
            counter ++;
            i ++;
        }

        else if(isVowel(words[i][0])){
            counter ++;
            i++;
        }
        else if(isVowel(words[i + 2][0])){
            counter += 3;
            i += 3;
        }
        else if(isVowel(words[i + 1][0])){
            counter += 2;
            i ++; i++;
        }
        else if(isVowel(words[i + 1][1])){
            counter += 3;
            i++; i++;
        }
        else if(!isVowel(words[i][1]) && !isVowel(words[i][2])){
            cout << "*\n";
            return;
        }
        else if(isVowel(words[i][1])){
            counter += 2;
            i++;
        }
        else if(isVowel(words[i][2])){
            counter += 3;
            i++;
        }
    }
    cout << counter << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}