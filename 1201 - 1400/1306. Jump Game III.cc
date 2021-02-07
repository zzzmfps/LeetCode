// 36 ms, 97.33%; 31.3 MB, 78.91%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(const vector<int> &arr, int start) {
        vector<bool> visited(arr.size());
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            int l = index - arr[index], r = index + arr[index];
            if (l >= 0 && !visited[l]) visited[l] = true, q.push(l);
            if (r < arr.size() && !visited[r]) visited[r] = true, q.push(r);
        }

        bool flag = false;
        for (int i = 0; !flag && i < arr.size(); ++i) {
            if (arr[i]) continue;
            flag = visited[i];
        }
        return flag;
    }
};
