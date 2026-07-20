class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //Binary search
        vector<int> tail;
        

        for (int x:nums) {
            auto it=lower_bound(tail.begin(),tail.end(),x);

            if(it==tail.end()){
                tail.push_back(x);
            }else{
                *it=x;
            }
        }

        return tail.size();
    }
};