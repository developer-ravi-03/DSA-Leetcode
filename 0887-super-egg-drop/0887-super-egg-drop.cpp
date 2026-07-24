class Solution {
public:

    int helper(int eggs, int floors,vector<vector<int>> &dp){
        if(floors==0 || floors==1){
            return floors;
        }

        if(eggs==1) return floors;

        if(dp[floors][eggs]!=-1) return dp[floors][eggs];

        //Memoization + Binary search

        int low=1;
        int high=floors;
        int ans=1e9;
        while(low<=high){

            int mid=low+(high-low)/2;
            int breakCase=helper(eggs-1,mid-1,dp);
            int notBreakCase=helper(eggs,floors-mid,dp);

            int temp=1+max(breakCase,notBreakCase);

            ans=min(temp,ans);

            if(breakCase<notBreakCase){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return dp[floors][eggs]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return helper(k,n,dp);
    }
};