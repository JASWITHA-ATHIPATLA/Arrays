// leetcode-problem-387. First Unique Character in a String

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        map<char,int>mapp;
        for(int i=0;i<n;i++){
            mapp[s[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(mapp[s[i]]==1)return i;
        }
        return -1;
    }

};
int main(){
 string s;
 cin>>s;
 Solution obj;
 int ans=obj.firstUniqChar(s);
 cout<<"Unique first character"<<ans;
 return 0;
}