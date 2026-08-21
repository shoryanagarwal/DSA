class Solution {
private:

    int solve(vector<int> &nums,int start,vector<int> &dp,int end){

        if(end==start){
            return nums[start];
        }
        if(end<start){
            return 0;
        }

        if(dp[end]!=-1){
            return dp[end];
        }


        int include=solve(nums,start,dp,end-2)+ nums[end];
        int exclude=solve(nums,start,dp,end-1);

        dp[end]=max(include,exclude);
        return dp[end];





    }



public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        

        if(n==1){
            return nums[0];
        }

        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        return max(solve(nums,0,dp1,n-2),solve(nums,1,dp2,n-1));
    }
};