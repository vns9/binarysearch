// https://binarysearch.com/problems/Bounded-Square-Sums

int helper(int lower, int upper, vector<int>& v){
    int n=v.size();
    if(n==0) return 0;
    int p1=-1;
    int p2=-1;
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]*v[mid]<lower){
            lo=mid+1;
        }
        else{
            p1=mid;
            hi=mid-1;
        }
    }
    lo=0;
    hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]*v[mid]>upper){
            hi=mid-1;
        }
        else{
            p2=mid;
            lo=mid+1;
        }
    }
    if(p1==-1||p2==-1) return 0;
    return p2-p1+1;
}
int solve(vector<int>& a, vector<int>& b, int lower, int upper) {
    int ans=0;
    for(int i=0;i<b.size();i++) b[i]=abs(b[i]);
    sort(b.begin(),b.end());
    for(auto val:a){
        ans+=helper(lower-val*val, upper-val*val, b);
    }
    return ans;
}
