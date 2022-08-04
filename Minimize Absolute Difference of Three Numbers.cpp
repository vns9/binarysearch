// https://binarysearch.com/problems/Minimize-Absolute-Difference-of-Three-Numbers

int helper(int val, vector<int>& v){
    int abs_diff=INT_MAX;
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        abs_diff=min(abs_diff, abs(val-v[mid]));
        if(v[mid]<val){
            lo=mid+1;
        }
        else if(v[mid]>val){
            hi=mid-1;
        }
        else{
            break;
        }
    }
    return abs_diff;
}
int solve(vector<int>& a, vector<int>& b, vector<int>& c) {
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    int ans=INT_MAX;
    for(auto val:b){
        ans=min(ans, helper(val,a)+helper(val,c));
    }
    return ans;
}
