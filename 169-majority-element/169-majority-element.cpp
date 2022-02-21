class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = INT_MAX;
        int count = 0;
        for (int n : nums) {
            if (res == n) ++count;
            else {
                if (count == 0) {
                    res = n;
                    ++count;
                }
                else --count;
            }
        } // for
        return res;
    }
};