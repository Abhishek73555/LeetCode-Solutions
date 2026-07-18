class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>v(n+m);
        int i=n-1;
        int j=m-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                v[k]=nums1[i];
                k--;
                i--;
            }else{
                v[k]=nums2[j];
                k--;
                j--;
            }
        }
        while(i>=0){
            v[k]=nums1[i];
            k--;
            i--;
        }
        while(j>=0){
            v[k]=nums2[j];
            k--;
            j--;
        }
        int mid=(m+n)/2;
        if((m+n)%2==0){
            float med=(v[mid]+v[mid-1])/2.0;
            return med;
        }else{
            return v[mid];
        }

    }
};