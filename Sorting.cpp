#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partition(vector<int>&nums,int low,int high){
        int pivot=nums[low];
        int i=low;
        int j=high;
        while(i<j){
            while(nums[i]<=pivot && i<=high-1){
                i++;
                }
            while(nums[j]>pivot && j>=low+1){j--;}
            if(i<j) {
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[j],nums[low]);
        return j;
    }
    void qsort(vector<int>&nums,int low,int high){
         if(low<high){
            int Pindex=partition(nums,low,high);
            qsort(nums,low,Pindex-1);
            qsort(nums,Pindex+1,high);            
        }  
    }
    vector<int> sortArray(vector<int>& nums) {
       qsort(nums,0,nums.size()-1);
      return nums;
    }
};
int main(){
 int n;
 cout<<"enter n value:"<<endl;
 cin>>n;
 vector<int>nums;
 cout<<"enter numbers to sort:"<<endl;
 for(int i=0;i<n;i++){
  int value;
  cin>>value;
  nums.push_back(value);
 }
 Solution obj;
 obj.sortArray(nums);
 cout<<"The output array: ";
 for(int i=0;i<n;i++){
  cout<<nums[i]<<" ";
 }
 return 0;
}