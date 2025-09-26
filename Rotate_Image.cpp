//leetcode problem-48 2D-arrays
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseRows(vector<vector<int>>&matrix,int n,int i){
             int ptr1=0,ptr2=n-1;
             while(ptr1<ptr2){               
                    swap(matrix[i][ptr1],matrix[i][ptr2]);
                    ptr1++;ptr2--;
             }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1)return;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){               
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
           reverseRows(matrix,n,i);
        }
        
    }
};