// https://binarysearch.com/problems/Update-List-Sum-Closest-to-Target

int solve(vector<int>& nums, int target) {
    pair<int,int> diffidx={INT_MAX,-1};
    int lo=0;
    int hi=*max_element(nums.begin(),nums.end());
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int sum=0;
        for(auto num: nums){
            sum+=min(num,mid);
        }
        
        if(diffidx.first>abs(target-sum)){
            diffidx = {abs(target-sum),mid};
        }
        else if(diffidx.first==abs(target-sum) && mid<diffidx.second){
            diffidx = {abs(target-sum),mid};
        }

        if(sum>target){
            hi=mid-1;
        }
        else if(sum<target){
            lo=mid+1;
        }
        else{
            break;
        }
    }
    return diffidx.second;
}
