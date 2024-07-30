#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::stack<std::pair<int, int>> stk;
        int prev = -1;
        int val = -1;
        int count = 0;
        
        for (int i : ratings) {
            if (stk.empty() || stk.top().first >= i)
                // Cada criança deve ter pelo menos um doce
                stk.push({i, 1});
            else if (stk.top().first < i)
                stk.push({i, stk.top().second + 1});
        }
        
        while (!stk.empty()) {
            if (prev == -1 || stk.top().first <= prev) {
                auto temp = stk.top(); stk.pop();
                prev = temp.first;
                val = temp.second;
            } else if (prev < stk.top().first) {
                if (val >= stk.top().second) {
                    prev = stk.top().first;
                    stk.pop();
                    val = val + 1;
                } else {
                    auto temp = stk.top(); stk.pop();
                    prev = temp.first;
                    val = temp.second;
                }
            }
            count += val;
        }
        return count;
    }
};
