#include <bits/stdc++.h>

int disjoint[10000];

class Solution {
public:

    void join(int parent, int child){
    disjoint[parent] += disjoint[child];
    disjoint[child] = parent;
    }

    int finder(int index){
        while(disjoint[index] >= 0){
            index = disjoint[index];
        }
        return index;
    }

    bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
        for(int i = 0; i < 10000; i ++){
            disjoint[i] = -1;
        }
        int pa, pb;
        for(int i = 0; i < n; i ++){
            if(leftChild[i] != -1){
                if(disjoint[leftChild[i]] >= 0) return false;
                pa = finder(i);
                pb = finder(leftChild[i]);
                if(pa == pb)return false;
                join(pa, pb);
            }
            if(rightChild[i] != -1){
                if(disjoint[rightChild[i]] >= 0) return false;
                pa = finder(i);
                pb = finder(rightChild[i]);
                if(pa == pb)return false;
                join(pa, pb);
            }
        }
        if(std::abs(disjoint[finder(0)]) == n) return true;
        return false;
    }
        
};