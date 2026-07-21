class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        map<int,int>startToIndex; 
        for(int i=0;i<n;++i) startToIndex[intervals[i][0]]=i;
        vector<int>ans(n);
        for(int i=0;i<n;++i){
            auto it=startToIndex.lower_bound(intervals[i][1]);            
            if(it==startToIndex.end()) ans[i] = -1; 
            else ans[i] = it->second;
        }
        return ans;
    }
};