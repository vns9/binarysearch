// https://binarysearch.com/problems/Find-Local-Peaks-Sequel

vector<int> solve(vector<int>& nums) {
    vector<int> ans;
    pair<int,int> prev1={-1,0};
    pair<int,int> prev2={-1,0};
    int index=0;
    while(index<nums.size()){
        int currcnt=0;
        for(int i=index; i<nums.size(); i++){
            if(nums[i]!=nums[index]){
                break;
            }
            else currcnt++;
        }
        if(prev1.first==-1){
            prev1={index,currcnt};
        }
        else if(prev2.first==-1){
            if(prev1.first==0 && nums[index]<nums[0]){
                for(int j=prev1.first; j<prev1.first+prev1.second; j++){
                    ans.push_back(j);
                }    
            }
            if(index+currcnt==nums.size() && nums[prev1.first]<nums[index]){
                for(int j=index; j<nums.size(); j++){
                    ans.push_back(j);
                }
            }
            prev2={index,currcnt};
        }
        else{
            if(nums[prev2.first]>nums[index]&&nums[prev2.first]>nums[prev1.first]){
                for(int j=prev2.first; j<prev2.first+prev2.second; j++){
                    ans.push_back(j);
                }
            }
            if(index+currcnt==nums.size() && nums[prev2.first]<nums[index]){
                for(int j=index; j<nums.size(); j++){
                    ans.push_back(j);
                }
            }
            prev1=prev2;
            prev2={index,currcnt};
        }
        index=index+currcnt;
    }
    return ans;    
}
