#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

class Solution {
    public:
        int target;
        vector<bool> used;
        vector<int> nums;
        bool dfs(int left, int start, int c) {
            if (!left) {
                if (!c)
                    return true;
                return dfs(target, 0, c - 1);
            }
            unsigned i;
            for (i = start; i < nums.size() && nums[i] > left; ++i);
            for (; i < nums.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    if (dfs(left - nums[i], i + 1, c))
                        return true;
                    used[i] = false;
                }
            }
            return false;
        }
        bool makesquare(const vector<int>& nums) {
            if (nums.empty())
                return false;
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum % 4)
                return false;
            this->nums = nums;
            sort(this->nums.begin(), this->nums.end(), greater<int>());
            target = sum / 4;
            used = vector<bool>(nums.size(), false);
            return dfs(target, 0, 3);
        }
};

int main(void) {
    Solution s;
    s.makesquare({1,1,2,2,2});
    return 0;
}
