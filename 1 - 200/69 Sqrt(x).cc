// 18ms, 39.99%
class Solution
{
public:
    int mySqrt(int x)
    {
        long r = x;
        while(r * r > x)
            r = (r + x / r) / 2;
        return r;
        /*
        // Carmack's method
        int i;    // uint64_t for 8-bytes
        float x2 = x * 0.5;    // double for 8-bytes
        float y = x;
        i = *(int *) &y;
        i = 0x5F375A86 - (i >> 1);    // 0x5FE6EB50C7B537A9 for 64-bit
        y = *(float *)&i;
        y *= 1.5 - x2 * y * y;    // twice, or more
        y *= 1.5 - x2 * y * y;
        return 1.0 / y;
        */
    }
};
