// 3ms, 21.34%
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int beg = 1;
        while (beg <= n) {
            int mid = beg + (n - beg) / 2;
            int res = guess(mid);
            if (res > 0)
                beg = mid + 1;
            else if (res < 0)
                n = mid - 1;
            else
                return mid;
        }
    }
};
