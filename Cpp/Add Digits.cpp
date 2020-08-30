// 7ms, 8.82%
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
