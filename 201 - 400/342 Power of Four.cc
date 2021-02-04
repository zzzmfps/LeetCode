// 6ms, 23.27%
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && !(num & 0xAAAAAAAA);
    }
};
