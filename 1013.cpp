
/* 1013. 将数组分成和相等的三个部分
 * https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
 * 
 */


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {
        int sum = 0;
        for(int num:nums) sum += num;
              
        int target = sum / 3;
        int s = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i ++) {
            s += nums[i];
            if (s == target) {
                count ++;
                if (i < nums.size() - 1 && count == 2) return true;
                s = 0;
            }
        }

        return false;
    }
};