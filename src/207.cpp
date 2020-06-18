#include <vector>
#include <stack>

using namespace std;

class Solution {
    private:
        vector<vector<int>> gout;
        vector<int> gin;
    public:
        bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
            gout = vector<vector<int>>(numCourses);
            gin = vector<int>(numCourses);
            for (auto e : prerequisites) {
                gout[e[1]].push_back(e[0]);
                ++gin[e[0]];
            }
            stack<int> s;
            for (int i = 0; i < numCourses; ++i)
                if (gin[i] == 0)
                    s.push(i);
            while (s.size()) {
                int c = s.top();
                s.pop();
                for (auto t : gout[c]) {
                    --gin[t];
                    if (!gin[t])
                        s.push(t);
                }
            }
            for (int i = 0; i < numCourses; ++i)
                if (gin[i])
                    return false;
            return true;
        }
};
