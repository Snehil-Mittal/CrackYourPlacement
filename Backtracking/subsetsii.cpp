#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;

class Solution {
public:
    set<vector<int>> subsetsWithDupHelp(vector<int>& nums,int index,set<vector<int>> &result,vector<int> &temp) {
    
        result.insert(temp);
        if(index==-1){
            return result;
        }
        else
        {
        temp.push_back(nums[index]);
        subsetsWithDupHelp(nums,index-1,result,temp);
        temp.pop_back();
        }
        subsetsWithDupHelp(nums,index-1,result,temp);
        return result;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        set<vector<int>> result;
        vector<int> temp;
        result=subsetsWithDupHelp(nums,nums.size()-1,result,temp);
        vector<vector<int>> res(result.begin(),result.end());
        return res;
    }

};