// https://binarysearch.com/problems/Eat-Bananas-in-K-Hours

int solve(vector<int>& piles, int k) {
    int ans=-1;
    int lo=1;
    int hi=*max_element(piles.begin(),piles.end());
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int timetaken=0;
        for(auto pile:piles){
            timetaken+=(pile/mid);
            if(pile%mid!=0) timetaken++;
        }
        if(timetaken>k){
            lo=mid+1;
        }
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    return ans;
}
