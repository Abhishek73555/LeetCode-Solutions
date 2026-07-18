class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // vector<int> dp(n,1);
        // int ans = 1;
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(nums[j][0] < nums[i][0] &&
        //            nums[j][1] < nums[i][1]){
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        //     ans = max(ans, dp[i]);
        // }

        sort(envelopes.begin(), envelopes.end(),
        [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> lis;
        for(int i = 0; i < envelopes.size(); i++){
            int h = envelopes[i][1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if(it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }
        return lis.size();
    }
};

       