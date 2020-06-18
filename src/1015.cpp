class Solution {
    public:
        int smallestRepunitDivByK(int K) {
            int c = 1;
            int i = 1;
            while (c <= K) {
                if (K % c == 0)
                    return i;
                c = c * 10 + 1;
                ++i;
            }
            return -1;
        }
};
