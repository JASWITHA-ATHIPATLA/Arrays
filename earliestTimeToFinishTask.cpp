// leetcode problem-3683-Earliest Time to Finish One Task

// You are given a 2D integer array tasks where tasks[i] = [si, ti].

// Each [si, ti] in tasks represents a task with start time si that takes ti units of time to finish.

// Return the earliest time at which at least one task is finished.
// Example 1:

// Input: tasks = [[1,6],[2,3]]

// Output: 5

// Explanation:

// The first task starts at time t = 1 and finishes at time 1 + 6 = 7.
// The second task finishes at time 2 + 3 = 5. You can finish one task at time 5.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(auto it:tasks[i]){
                sum+=it;
            }
            mini=min(mini,sum);
        }
        return mini;
    
    }
};