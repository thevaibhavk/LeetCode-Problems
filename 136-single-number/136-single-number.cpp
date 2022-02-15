class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int x=nums[0];
        int n = nums.size();
            for(int i=1;i<n;i++)
            {
                x= x^nums[i]; 
            }
            return x;
    }
};