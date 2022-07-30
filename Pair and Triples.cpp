// https://binarysearch.com/problems/Pair-and-Triples

bool solve(string s) {
    vector<int> dp(10);
    int rem0=0;
    int rem2=0;
    for(auto c: s) dp[c-'0']++;
    for(auto cnt: dp){
        if(cnt%3==2) rem2++;
        if(cnt%3==0) rem0++;
    }
    if(rem2==1&&rem0==9) return true;
    return false;
}
