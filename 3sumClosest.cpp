//leetcode-prob-16/3sumClosest
// Intuition
// This solution solves 100% problems 2sum,3sum,4sum all similar intution.

// Approach
// Brute:
// Brute is always using nested for loops try to relate inner for loops with outer for loops . for all 2sum,3sum,4sum same approach.
// # Better:
// Using hashing hashset datastructure for 2sum

// Optimal: three pointer approach as this is 3sum
// 1.sort the array
// 2.start looping from 0 to size of array.intialize three pointers
// i=0,j=i+1,k=n-1;
// 3.store the min sum in entire array.
// 4.if the sum>target then move left else move right .return the min sum that is the closest number to target

// Complexity
// Time complexity:
// O(n^2+nlog(n))-for iteration through entire array and sort the array

// Space complexity:
// O(1)--not using any extra space to store

// Code
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(closest-target)){
                    closest=sum;
                }
                if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return closest;
    }
};
int main(){
 int n;
 cin>>n;
 vector<int>nums;
 for(int i=0;i<n;i++){
  int number;
  cin>>number;
  nums.push_back(number);
 }
 int target;
 cin>>target;
  Solution s;
  int ans=s.threeSumClosest(nums,target);
  cout << "Output: " << ans << endl;

 return 0;
}

