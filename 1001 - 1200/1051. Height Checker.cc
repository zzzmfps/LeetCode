#include <bits/stdc++.h>
using namespace std;

// 0, brute force, T(n) = O(nlogn)
// 4ms, 63.30%; 7.7MB, 100.00%
class Solution0 {
public:
    int heightChecker(const vector<int> &heights) {
        vector<int> tmp(heights);
        sort(tmp.begin(), tmp.end());
        int count = 0;
        for (int i = 0; i < heights.size(); ++i)
            if (heights[i] != tmp[i]) count += 1;
        return count;
    }
};

// 1, based on count-sort, T(n) = O(n)
// 0ms, 100.00%; 7.7MB, 100.00%
class Solution1 {
public:
    int heightChecker(const vector<int> &heights) {
        int counts[101] = {}, res = 0;
        for (auto h : heights) counts[h] += 1;
        for (int i = 1, j = 0; i < 101; ++i)
            while (counts[i]--)
                if (i != heights[j++]) res += 1;
        return res;
    }
};
