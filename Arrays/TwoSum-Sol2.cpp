#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            result.push_back(i);
            for(int j=0;j<nums.size();j++)
            {
                if((target-nums[i])==nums[j] && j!=i){
                    result.push_back(j);
                    break;
                }
            }
            if(result.size()==2)
                break;
            result.clear();
        }
        return result;
    }
};