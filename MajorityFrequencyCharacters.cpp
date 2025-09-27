// leetcode contest 466:problem-3692. Majority Frequency Characters
// Intuition
// The intution is simple when ever prefetching/frequency comes the map data structure is used.

// Approach
// 1.store frequencies into map ds
// 2.group by frequencie
// 3.compare the size to find maximum distint group with highest frequency.

// Complexity
// Time complexity:
// O(NlogN)--for storing into map and iterating through map
// Space complexity:
// O(N)--at worst case when all are distint chars in string
// Code
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n=s.size();
        map<char,int>mapp;
        for(int i=0;i<n;i++){
            mapp[s[i]]++;
        }
        map<int,string>groups;
        for(auto &it :mapp){
            groups[it.second].push_back(it.first);
        }
        string res;
        int maxi=0,bestfreq=0;
        for(auto &g:groups){
            int k=g.second.size();
            int freq=g.first;
            if(k>maxi || (k==maxi && freq>bestfreq)){
                bestfreq=freq;
                maxi=k;
                res=g.second;
            }
        }
        return res;
    }
};