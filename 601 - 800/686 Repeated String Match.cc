// 0ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int repeatedStringMatch(const string &A, const string &B)
    {
        int asize = A.size(), bsize = B.size(), left = B.find(A);
        if (left == -1 && asize * 2 - 2 < bsize || left >= asize) return -1;
        if (left == -1) return A.find(B) != -1 ? 1 : repeatString(A, 2).find(B) != -1 ? 2 : -1;
        int num = (bsize - left) / asize, right = (bsize - left) % asize;
        string tmp = A.substr(asize - left) + repeatString(A, num) + A.substr(0, right);
        return tmp == B ? min(1, left) + num + min(1, right) : -1;
    }

  private:
    string repeatString(const string &x, int num)
    {
        string ret = x;
        while (--num) ret += x;
        return ret;
    }
};
