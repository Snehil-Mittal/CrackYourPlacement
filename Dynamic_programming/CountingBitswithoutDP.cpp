#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++){
            int count=0;
            int num=i;
            while(num!=0){
                count+=(num%2);
                num=num/2;
            }
            result.push_back(count);
        }
        return result;
    }
};