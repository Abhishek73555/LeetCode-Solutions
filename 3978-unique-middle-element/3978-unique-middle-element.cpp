class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        if (nums.empty()) return false; 
        return count(nums.begin(),nums.end(),nums[nums.size()/2])==1;
    }
};