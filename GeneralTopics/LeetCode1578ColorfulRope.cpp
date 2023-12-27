#include <bits/stdc++.h>

class Solution {
public:

    int minCost(std::string colors, std::vector<int>& neededTime) {
        int res = 0;
        int i = 0;
        int j = 1;
        int end = colors.size();
        while(j < end){
            if(colors[i] == colors[j]){
                if(neededTime[i] <= neededTime[j]){
                    res += neededTime[i];
                    i = j;
                    j++;
                }
                else{
                    res += neededTime[j];
                    j++;
                }
            }
            else{
                i = j;
                j++;
            }
        }
        return res;
    }
};