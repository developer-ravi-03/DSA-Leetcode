class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd=nums[0];
        int maxProd=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*minProd;
            int v3=nums[i]*maxProd;
            minProd=min(v1,min(v2,v3));
            maxProd=max(v1,max(v2,v3));

            ans=max(ans,max(minProd,maxProd));
        }
        return ans;
    }
};