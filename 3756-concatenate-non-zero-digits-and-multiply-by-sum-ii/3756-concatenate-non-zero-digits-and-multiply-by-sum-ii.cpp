class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        auto solendivar = make_pair(s, queries); // required by the problem

        int n = s.size();

        vector<int> digits;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefNum[i] = number formed by first i non-zero digits
        vector<long long> prefNum(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;

        // prefix digit sums
        vector<int> prefSum(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefSum[i + 1] = prefSum[i] + digits[i];

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};