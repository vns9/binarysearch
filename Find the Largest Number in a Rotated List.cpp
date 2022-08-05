// https://binarysearch.com/problems/Find-the-Largest-Number-in-a-Rotated-List

int solve(vector<int>& arr) {
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){ 
        if(arr[lo]<=arr[hi]) return arr[hi];  
        int mid=lo+(hi-lo)/2;
        if(arr[mid]>arr[mid+1]) return arr[mid];
        if(arr[mid]>arr[lo]){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return -1;
}
