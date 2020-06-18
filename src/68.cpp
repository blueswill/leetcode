#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
    private:
        // acc[i] the length of words[0..i)
        vector<unsigned> acc;
        // mlen[i] the max length of words if start from words[i]
        vector<unsigned> mlen;
        vector<string> words;
        vector<string> res;
        unsigned maxWidth;

        void init() {
            acc.clear();
            mlen.clear();
            acc.push_back(0);
            for (unsigned i = 0; i < words.size(); ++i)
                acc.push_back(acc.back() + words[i].size());
            for (unsigned i = 1; i < acc.size(); ++i) {
                if (acc[i] + i - 1 > maxWidth) {
                    mlen.push_back(i - 1);
                    break;
                }
                else if (acc[i] + i - 1 == maxWidth) {
                    mlen.push_back(i);
                    break;
                }
            }
            if (mlen.size() == 0)
                mlen.push_back(words.size());
            for (unsigned i = 1; i < words.size(); ++i) {
                unsigned p = acc[i + mlen[i - 1] - 1] - acc[i];
                for (unsigned j = i + mlen[i - 1] - 1; j < words.size(); ++j) {
                    unsigned len = j - i + 1;
                    p += words[j].size();
                    if (p + len - 1 > maxWidth) {
                        mlen.push_back(len - 1);
                        break;
                    }
                    else if (p + len - 1 == maxWidth) {
                        mlen.push_back(len);
                        break;
                    }
                }
                if (mlen.size() != i + 1)
                    mlen.push_back(words.size() - i);
            }
        }

        void search(unsigned start) {
            while (start < words.size()) {
                unsigned len = mlen[start];
                unsigned word_len = acc[start + len] - acc[start];
                unsigned left = maxWidth - word_len;
                if (start + len == words.size()) {
                    string tmp = words[start];
                    for (unsigned i = 1; i < len; ++i) {
                        tmp.push_back(' ');
                        tmp.append(words[start + i]);
                    }
                    tmp.insert(tmp.end(), maxWidth - tmp.size(), ' ');
                    res.push_back(tmp);
                }
                else if (len == 1) {
                    string tmp = words[start];
                    tmp.insert(tmp.end(), left, ' ');
                    res.push_back(tmp);
                }
                else {
                    unsigned basic = left / (len - 1),
                             pad = left % (len - 1);
                    string tmp = words[start];
                    for (unsigned i = 1; i < len; ++i) {
                        unsigned add = !!pad;
                        pad -= add;
                        tmp.insert(tmp.end(), basic + add, ' ');
                        tmp.append(words[start + i]);
                    }
                    res.push_back(tmp);
                }
                start += len;
            }
        }
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            this->words = words;
            this->maxWidth = maxWidth;
            if (words.size() == 0)
                return {string(' ', maxWidth)};
            res.clear();
            acc.clear();
            init();
            search(0);
            return res;
        }
};

int main(void) {
    vector<string> test{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    Solution s;
    s.fullJustify(test, 20);
    return 0;
}
