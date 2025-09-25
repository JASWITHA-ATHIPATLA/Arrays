// leet code prob:1Two Sum-asked by google meta..
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<long long,int>mapp;
        vector<int>ans;long long sum=0;
        for(int i=0;i<n;i++){
           long long more=target-nums[i];
           if(mapp.find(more)!=mapp.end()){
                ans.push_back(mapp[more]);
                ans.push_back(i);
                return ans;
           }
           mapp[nums[i]]=i;
        }
        return ans;
    }
};
