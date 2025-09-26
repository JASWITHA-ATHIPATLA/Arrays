//leetcode problem-48 2D-arrays
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
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