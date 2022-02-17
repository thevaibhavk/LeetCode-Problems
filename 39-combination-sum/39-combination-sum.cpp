class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int id, int target, vector<int>& v, vector<int>& arr){
        
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        if(id>=arr.size()){
            return;
        }
        
        if(arr[id]<=target){
            v.push_back(arr[id]);
            solve(id, target-arr[id], v, arr);
            v.pop_back();
        }
        solve(id+1, target, v, arr);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        
        vector<int> v;
        solve(0,target,v,arr);
        return ans;
    }
};