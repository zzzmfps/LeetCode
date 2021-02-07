// 12ms, 80.10%; 9.3MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int> arr1, vector<int> arr2) {
        helper(arr1, arr2);
        int i = arr1.size(), carry1 = 0, carry2 = 0;
        while (--i > -1) {
            arr1[i] += arr2[i] + carry2;
            if (arr1[i] == 4) {
                arr1[i] = 0, carry2 = carry1, carry1 = 1;
            } else if (arr1[i] >= 2) {
                arr1[i] -= 2, carry2 = 1 + carry1, carry1 = 1;
            } else {
                carry2 = carry1, carry1 = 0;
            }
        }
        if (carry1 != 1 || carry2 != 2) arr1.insert(arr1.begin(), {carry1, carry2});
        auto idx = find(arr1.begin(), arr1.end(), 1);
        return (idx == arr1.end() ? vector<int>(1) : vector<int>(idx, arr1.end()));
    }

private:
    void helper(vector<int> &arr1, vector<int> &arr2) {
        int size1 = arr1.size(), size2 = arr2.size();
        if (size1 < size2) {
            arr1.insert(arr1.begin(), size2 - size1, 0);
        } else {
            arr2.insert(arr2.begin(), size1 - size2, 0);
        }
    }
};
