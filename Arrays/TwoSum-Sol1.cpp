#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end() && i!=m[target-nums[i]]){
                result.push_back(i);
                result.push_back(m[target-nums[i]]);
                break;
            }
        }
        return result;
    }
};