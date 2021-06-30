// 0ms, 100.00%; 8.7MB, 10.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(const vector<int> &nums) {
        int size = nums.size();
        vector<bool> isVisited(size, false);
        for (int i = 0; i < size; ++i) {
            if (!isVisited[i]) {
                isVisited[i] = true;
                if (helper(nums, i, isVisited)) return true;
            }
        }
        return false;
    }

private:
    bool helper(const vector<int> &nums, int i, vector<bool> &isVisited) {
        int size = nums.size();
        int j = (i + nums[i]) % size;
        if (j < 0) j += size;
        unordered_set<int> tmp;
        tmp.insert(i);
        while (true) {
            if (i == j || nums[i] * nums[j] < 0) return false;
            if (isVisited[j] && tmp.find(j) != tmp.end()) return true;
            isVisited[j] = true;
            tmp.insert(j);
            i = j, j = (j + nums[j]) % size;
            if (j < 0) j += size;
        }
        return false;
    }
};
