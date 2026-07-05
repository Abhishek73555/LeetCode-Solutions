class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxD=-1;
        int i=0;
        int j=1;
        while(j<nums.size()){
            if(nums[i]<nums[j]){
                maxD=max(maxD,nums[j]-nums[i]);
                j++; 
            }else{
                i=j; 
                j++;   
            }
        }
        return maxD;
    }
};