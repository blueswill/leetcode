#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        string target;
        vector<string> res;

        void search(int sum, int left, int right) {
            if (left == 0) {
                string tmp = target;
                tmp.append(string(right, ')'));
                res.push_back(tmp);
                return;
            }
            target.push_back('(');
            search(sum + 1, left - 1, right);
            target.pop_back();
            if (sum > 0) {
                target.push_back(')');
                search(sum - 1, left, right - 1);
                target.pop_back();
            }
        }
    public:
        vector<string> generateParenthesis(int n) {
            target.clear();
            res.clear();
            search(0, n, n);
            return res;
        }
};
