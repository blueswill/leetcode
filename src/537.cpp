#include <string>

using namespace std;

class Solution {
    private:
        int parse_int(const string &s, int &p) {
            int neg = 1;
            int res = 0;
            if (s[p] == '-') {
                neg = -1;
                ++p;
            }
            while (p < (int)s.size() && s[p] >= '0' && s[p] <= '9') {
                res = res * 10 + s[p] - '0';
                ++p;
            }
            return res * neg;
        }
    public:
        string complexNumberMultiply(string a, string b) {
            int s1[2], s2[2];
            int pos = 0; s1[0] = parse_int(a, pos);
            ++pos; s1[1] = parse_int(a, pos);
            pos = 0; s2[0] = parse_int(b, pos);
            ++pos; s2[1] = parse_int(b, pos);
            // (a + bi) * (c + di) = ac - bd + (ad + bc)i
            int r1 = s1[0] * s2[0] - s1[1] * s2[1];
            int r2 = s1[0] * s2[1] + s1[1] * s2[0];
            return to_string(r1) + "+" + to_string(r2) + "i";
        }
};
