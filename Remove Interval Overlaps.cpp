// https://binarysearch.com/problems/Remove-Interval-Overlaps

int solve(vector<vector<int>>& intervals) {
    int ans=0;
    int n=intervals.size();
    stack<vector<int>> st;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<n;i++){
        if(st.empty() || intervals[i][0]>=st.top()[1]){
            st.push(intervals[i]);
        }
        else if(st.top()[1]>intervals[i][1]){
            st.pop();
            st.push(intervals[i]);
            ans++;
        }
        else ans++;        
    }
    return ans;
}
