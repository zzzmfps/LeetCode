// 19ms, 29.18%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(const vector<int> &height) {
        int left = 0, right = height.size() - 1, volume = 0;
        do {
            int h = height[left] < height[right] ? height[left] : height[right];
            int v = (right - left) * h;
            volume = v > volume ? v : volume;
            if (height[left] < height[right])
                while (height[left] >= height[++left])
                    ;
            else
                while (height[right] >= height[--right])
                    ;
        } while (left < right);
        return volume;
    }
};
