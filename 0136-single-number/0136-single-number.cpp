class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> freq;
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])   count++;
            else{
                freq.push_back({nums[i-1],count});
                count=1;
            }
        }
        freq.push_back({nums.back(),count});
        for(int i = 0; i < freq.size(); i++){
            if(freq[i][1] == 1)
                return freq[i][0];
        }
        return -1;
    }
};