#include <string>

using namespace std;

class Solution {
    public:
        int numDupDigitsAtMostN(int n) {
            string N = to_string(n);
            int ex = 0;
            int acc = 9;
            for (unsigned i = 1; i < N.size(); ++i) {
                ex += acc;
                acc *= 10 - i;
            }
            bool used[10] = { false };
            int c = N[0] - '0' - 1;
            for (unsigned i = 1; i < N.size(); ++i)
                c *= 10 - i;
            ex += c;
            used[N[0] - '0'] = true;
            unsigned i;
            for (i = 1; i < N.size(); ++i) {
                c = 0;
                for (int j = 0; j < N[i] - '0'; ++j)
                    if (!used[j])
                        ++c;
                for (unsigned j = i + 1; j < N.size(); ++j) {
                    c *= 10 - j;
                }
                ex += c;
                if (used[N[i] - '0'])
                    break;
                used[N[i] - '0'] = true;
            }
            if (i == N.size())
                ++ex;
            return n - ex;
        }
};

int main(void) {
    Solution s;
    printf("%d\n", s.numDupDigitsAtMostN(20));
    return 0;
}
