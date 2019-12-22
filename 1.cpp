/*
1. Two Sum
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dict;
        vector<int> res = {0, 0};
        for(int i = 0; i < n; i ++)
        {
            int key = nums[i];
            if(dict.count(target - key))
            {
                res[0] = dict[target - key];
                res[1] = i;
                break;
            }
            
            dict[key] = i;
        }
        return res;
    }
};