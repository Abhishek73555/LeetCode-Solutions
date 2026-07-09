#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort: Start points ascending. If tied, end points descending.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int remainingCount = 0;
        int maxEndSoFar = INT_MIN;

        for (const auto& interval : intervals) {
            int currentEnd = interval[1];

            // If the current interval extends past the maximum end seen so far,
            // it is NOT covered by any previous interval.
            if (currentEnd > maxEndSoFar) {
                remainingCount++;
                maxEndSoFar = currentEnd; // Update the tracking boundary
            }
            // If currentEnd <= maxEndSoFar, it is completely covered and ignored.
        }

        return remainingCount;
    }
};
