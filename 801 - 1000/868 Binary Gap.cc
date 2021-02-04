// 4ms, 99.62%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int binaryGap(int N)
    {
        if ((N & (N - 1)) == 0) return 0;
        int ret = 1, lastIdx = 0;
        string binNum = getBinaryNumber(N);
        while (true) {
            int idx1 = binNum.find('0', lastIdx);
            if (idx1 == string::npos) break;
            int idx2 = binNum.find('1', idx1 + 1);
            if (idx2 == string::npos) break;
            ret = max(ret, idx2 - idx1 + 1);
            lastIdx = idx2 + 1;
        }
        return ret;
    }

  private:
    string getBinaryNumber(int n)
    {
        string ret = "";
        while (n) {
            ret += to_string(n & 1);
            n >>= 1;
        }
        return string(ret.rbegin(), ret.rend());
    }
};
