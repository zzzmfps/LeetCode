// 136ms, 99.19%; 44.5MB, 98.46%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        if (dislikes.empty()) return true;
        
        auto cmp = [](vector<int> &x, vector<int> &y) {
            return x[0] < y[0] || x[0] == y[0] && x[1] < y[1];
        };
        sort(dislikes.begin(), dislikes.end(), cmp);

        int *arr = new int[N + 1]{};
        arr[dislikes[0][0]] = 1;

        while (!dislikes.empty()) {
            vector<vector<int>> tmp;
            for (auto &d : dislikes) {
                int x = d[0], y = d[1];
                if (arr[x] == arr[y]) {
                    if (arr[x]) return false;
                    tmp.push_back(d);
                } else if(arr[x]){
                    arr[y] = arr[x] ^ 3;
                } else {
                    arr[x] = arr[y] ^ 3;
                }
            }
            if (dislikes.size() == tmp.size()) arr[dislikes[0][0]] = 1;
            dislikes.swap(tmp);
        }
        return true;
    }
};
