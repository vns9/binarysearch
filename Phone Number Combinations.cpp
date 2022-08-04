// https://binarysearch.com/problems/Phone-Number-Combinations 

vector<string> ans;
void backtrack(string curr, int i, string digits, map<int,string>& dial){
    if(curr.size()==digits.size()){
        ans.push_back(curr);
        return;
    }
    for(int j=0;j<dial[digits[i]-'0'].size();j++){
        curr+=dial[digits[i]-'0'][j];
        backtrack(curr,i+1,digits,dial);
        curr.pop_back();
    }
}
vector<string> solve(string digits) {
    map<int,string> dial;
    dial[2]="abc";
    dial[3]="def";
    dial[4]="ghi";
    dial[5]="jkl";
    dial[6]="mno";
    dial[7]="pqrs";
    dial[8]="tuv";
    dial[9]="wxyz";
    backtrack("",0,digits,dial);
    auto retans=ans;
    ans.clear();
    return retans;
}
