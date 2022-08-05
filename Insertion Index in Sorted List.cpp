// https://binarysearch.com/problems/Insertion-Index-in-Sorted-List

int solve(vector<int>& nums, int target) {
    int ans=-1;
    int lo=0;
    int hi=nums.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]<=target){
            lo=mid+1;
        }
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    if(ans==-1 && nums.back()<=target) return nums.size();
    return ans;
}
