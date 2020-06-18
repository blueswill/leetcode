#include <vector>
#include <string>

using std::string;
using std::vector;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
        // Constructor initializes an empty nested list.
        NestedInteger();

        // Constructor initializes a single integer.
        NestedInteger(int value);

        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

        // Set this NestedInteger to hold a single integer.
        void setInteger(int value);

        // Set this NestedInteger to hold a nested list and adds a nested integer to it.
        void add(const NestedInteger &ni);

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger> &getList() const;
};

class Solution {
    private:
        string target;

        NestedInteger parse_int(unsigned *cur) {
            long neg = 1;
            unsigned p = *cur;
            long res = 0;
            if (target[p] == '-') {
                neg = -1;
                ++p;
            }
            while (target[p] >= '0' && target[p] <= '9') {
                res = res * 10 + target[p] - '0';
                ++p;
            }
            *cur = p;
            return NestedInteger(res * neg);
        }
        // start points to [
        NestedInteger parse_bracket(unsigned *cur) {
            NestedInteger result;
            unsigned p = *cur + 1;
            while (p < target.size() && target[p] != ']') {
                switch (target[p]) {
                    case '[': result.add(parse_bracket(&p)); break;
                    case ',': ++p; break;
                    default: result.add(parse_int(&p)); break;
                }
            }
            *cur = p + 1;
            return result;
        }
    public:
        NestedInteger deserialize(string s) {
            target = s;
            unsigned p = 0;
            switch (s[0]) {
                case '[': return parse_bracket(&p);
                default: return parse_int(&p);
            }
        }
};
