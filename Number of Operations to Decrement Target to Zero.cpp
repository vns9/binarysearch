// https://binarysearch.com/problems/Number-of-Operations-to-Decrement-Target-to-Zero

int solve(vector<int>& nums, int target) {
    if(target==0) return 0;
    int ans=INT_MAX;
    int sum=-1*target;
    for(auto num:nums) sum+=num;
    map<int,int> mp;
    int currsum=0;
    mp[currsum]=-1;
    for(int i=0;i<nums.size();i++){
        currsum+=nums[i];
        if(mp.find(currsum)==mp.end()){
            mp[currsum]=i;
        }
        if(mp.find(currsum-sum)!=mp.end()){
            ans=min(ans,(int)nums.size()-(i-mp[currsum-sum]));
        }
    }    
    if(ans==INT_MAX) return -1;
    return ans;
}
