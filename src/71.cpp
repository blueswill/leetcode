#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    private:
        vector<string> res;
        string path;

        string next_val(unsigned i) {
            unsigned j;
            for (j = i; j < path.size() && path[j] != '/'; ++j);
            return path.substr(i, j - i);
        }
        
        void parse(void) {
            unsigned i = 0;
            while (i < path.size()) {
                if (path[i] == '/')
                    ++i;
                else {
                    string p = next_val(i);
                    i += p.size();
                    if (p == ".") continue;
                    else if (p == "..") {
                        if (res.size())
                            res.pop_back();
                    }
                    else res.push_back(p);
                }
            }
        }
    public:
        string simplifyPath(string path) {
            this->path = path;
            parse();
            if (res.empty())
                return "/";
            string r;
            for (auto &s : res)
                r.append("/" + s);
            return r;
        }
};
