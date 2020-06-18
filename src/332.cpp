#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    public:
        unordered_map<string, multiset<string>> graph;
        vector<string> res;
        void dfs(const string &cur) {
            auto &to = graph[cur];
            while (to.size()) {
                auto iter = to.begin();
                string c = *iter;
                to.erase(iter);
                dfs(c);
            }
            res.push_back(cur);
        }
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            graph.clear();
            res.clear();
            for (auto &t : tickets)
                graph[t[0]].insert(t[1]);
            dfs("JFK");
            return vector<string>(res.rbegin(), res.rend());
        }
};

