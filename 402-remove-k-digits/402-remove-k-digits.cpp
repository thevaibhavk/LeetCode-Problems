class Solution {
public:
    string removeKdigits(string num, int k) {
       for (int i = 0; i < k; i++) {
            int idx = 0;
            if (idx + 1 < num.size() && num[idx] <= num[idx + 1]) {
                idx++;
                while (idx + 1 < num.size() && num[idx + 1] >= num[idx]) 
                    idx++;
            }
            num.erase(idx, 1);
        }
        num.erase(0, num.find_first_not_of('0'));
        return num.size() > 0 ? num : "0";
    }

    
};