#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int rindex=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                continue;
            else{
                nums[rindex]=nums[i];
                rindex++;
            }
        }
        return rindex;
    }
};