class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        std::vector<int> answer;
        answer.reserve(nums.size());
        
        for (int num : nums) {
            int right_sum = total_sum - left_sum - num;
            answer.push_back(std::abs(left_sum - right_sum));
            left_sum += num;
        }
        
        return answer; 
    }
};