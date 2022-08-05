// https://binarysearch.com/problems/Skydivers

int solve(vector<int>& nums, int k) {
    int ans=-1;
    int n=nums.size();
    int lo=*max_element(nums.begin(),nums.end());
    int hi=0;
    for(auto num:nums) hi+=num;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int curr=0;
        int days_needed=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            if(curr==mid){
                days_needed++;
                curr=0;
            }
            else if(curr>mid){
                days_needed++;
                curr=nums[i];
            }
        }
        if(curr>0) days_needed++;
        if(days_needed<=k){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
