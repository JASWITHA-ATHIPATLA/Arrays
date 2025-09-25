// leetcode problem-165
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size();
        int n2=version2.size();
        int i1=0,i2=0;
        while(i1<n1 || i2<n2){
            int j1=i1;
            while(j1<n1){
                if(version1[j1]=='.')break;
                j1++;
            }
            int j2=i2;
            while(j2<n2){
                if(version2[j2]=='.')break;
                j2++;
            }
            int num1=0,num2=0;
            num1=i1<n1?stoi(version1.substr(i1,j1-i1)):0;
            num2=i2<n2?stoi(version2.substr(i2,j2-i2)):0;
            if(num1>num2)return 1;
            if(num1<num2)return -1;
            i1=j1+1;
            i2=j2+1;

        }
        return 0;
    }
};