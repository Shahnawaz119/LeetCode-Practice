class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        // reserve to avoid rehashing (optional but helps for big inputs)
        s.reserve(nums.size() * 2);
        s.max_load_factor(0.7f);

        int best = 0;
        for (const int &x : s) {
            // only start counting when x is potential sequence start
            if (s.find(x - 1) == s.end()) {
                int cur = x;
                int len = 1;
                while (s.find(cur + 1) != s.end()) {
                    cur++;
                    len++;
                }
                if (len > best) best = len;
            }
        }
        return best;
    }
};