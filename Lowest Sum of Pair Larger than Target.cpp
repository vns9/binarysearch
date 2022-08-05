// https://binarysearch.com/problems/Lowest-Sum-of-Pair-Larger-than-Target

int helper(int x, int i, int j, vector<int>& nums){
    int lo=i;
    int hi=j;
    int retans=INT_MAX;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]<=x){
            lo=mid+1;
        }
        else{
            retans=nums[mid];
            hi=mid-1;
        }
    }
    return retans;
}
int solve(vector<int>& nums, int target) {
    int n=nums.size();
    int ans=INT_MAX;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        int sum=nums[i];
        int call = helper(target-sum,i+1,n-1,nums);
        if(call!=INT_MAX){
            ans=min(ans,sum+call);
        } 
    }
    return ans;
}
