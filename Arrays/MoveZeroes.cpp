#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                break;
            }
        }
        for(j=i+1;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }
};