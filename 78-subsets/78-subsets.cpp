class Solution {
public:
    vector<vector<int>> res;
vector<int> temp;

void findSub(int idx, vector<int>& nums){
    if(idx==nums.size()){
        res.push_back(temp);
        return ;
    }
    
    temp.push_back(nums[idx]);
    findSub(idx+1, nums);
    temp.pop_back();
    findSub(idx+1, nums);
    
}

vector<vector<int>> subsets(vector<int>& nums) {
    
    findSub(0,nums);
    
    return res;
}
};