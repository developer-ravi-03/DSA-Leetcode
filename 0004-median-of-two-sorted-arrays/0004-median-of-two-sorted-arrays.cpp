class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<int>tmp;
        for(int n:nums1) tmp.push_back(n);
        for(int n:nums2) tmp.push_back(n);
        sort(tmp.begin(),tmp.end());

        double ans;
        int mid=0+(m+n)/2;
        if((m+n)%2==1){
            ans=tmp[mid];
        }else{
            ans=(tmp[mid]+tmp[mid-1])/2.0;
        }
        return ans;
    }
};