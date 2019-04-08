// 4ms, 100.00%; 9MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int videoStitching(const vector<vector<int>> &clips, int T)
    {
        int arr[101] = {};
        for (const auto &v : clips) arr[v[0]] = max(arr[v[0]], v[1]);
        int ret = 0, last = 0, cur = 0;
        while (cur < T) {
            int *tmp = max_element(arr + last, arr + cur + 1);
            if (*tmp <= cur) return -1;
            last = distance(arr, tmp) + 1;
            cur = *tmp;
            ret += 1;
        }
        return ret;
    }
};
