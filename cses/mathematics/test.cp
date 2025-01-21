#include<iostream>

int main() {


    long long int i = 1;
    long long int bruh[7] = {3LL, 163LL, 1697LL, 3503977LL, 7315807LL, 305656487LL, 52334929043LL};
    for(int j = 0; j < 7; j++) {
        i *= bruh[j];
        std::cout << i << std::endl;
    }
}
