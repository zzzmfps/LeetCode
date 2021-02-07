// 14ms, 20.18%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int units = 0;
        if (height.empty() || height.size() < 3) return units;

        for (int i = 0; i < height.size() - 2;) {
            int tmp = 0, h2 = 0;
            for (int j = i + 1; j < height.size(); ++j)
                if (height[j] >= height[i]) {
                    i = j;
                    units += tmp;
                    break;
                } else {
                    h2 = height[j] > h2 ? height[j] : h2;
                    if (j != height.size() - 1)
                        tmp += height[i] - height[j];
                    else {
                        height[i] = h2;
                        break;
                    }
                }
        }
        return units;
    }
};
