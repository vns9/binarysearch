// https://binarysearch.com/problems/Square-Submatrix-Sum-Below-Target

int solve(vector<vector<int>>& matrix, int target) {
    int ans=0;
    int lo=1;
    int hi=250;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-1>=0) matrix[i][j]+=matrix[i-1][j];
            if(j-1>=0) matrix[i][j]+=matrix[i][j-1];
            if(i-1>=0 && j-1>=0) matrix[i][j]-=matrix[i-1][j-1];
        }
    }
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        bool found=false;
        for(int row=mid-1;row<n;row++){
            if(found) break;
            for(int col=mid-1;col<m;col++){
                int currsum = matrix[row][col];
                if(row-mid>=0) currsum -= matrix[row-mid][col];
                if(col-mid>=0) currsum -= matrix[row][col-mid];
                if(col-mid>=0 && row-mid>=0) currsum += matrix[row-mid][col-mid];
                if(currsum<=target){
                    found=true;
                    break;
                }
            }
        }
        if(!found){
            hi=mid-1;
        }
        else{
            ans=mid;
            lo=mid+1;
        }
    }
    return ans*ans;
}
