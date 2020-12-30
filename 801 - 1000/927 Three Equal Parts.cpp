// 404ms, 8.84%; 12.1MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<int> threeEqualParts(const vector<int> &A)
    {
        int end = A.size() - 1;
        auto idx1 = find(A.begin(), A.end(), 1);
        if (idx1 == A.end()) return vector<int>{0, end};
        auto idx2 = find(A.rbegin(), A.rend(), 1).base();
        if (idx1 == idx2) return vector<int>{-1, -1};
        int i = distance(A.begin(), idx1), j = distance(A.begin(), idx2);

        while (i + 1 < j) {
            int flag02 = compare(A, 0, i, j, end);
            if (flag02 == 0) {
                int flag01 = compare(A, 0, i, i + 1, j - 1);
                if (flag01 == 0) return vector<int>{i, j};
                if (flag01 == 1) break;
            }
            if (flag02 == -1) {
                i += 1;
                continue;
            }
            j -= 1;
        }
        return vector<int>{-1, -1};
    }

private:
    int compare(const vector<int> &A, int i1, int i2, int j1, int j2)
    { // -1: less than, 0: equal to, 1: greater than
        int d1 = i2 - i1, d2 = j2 - j1;
        int length = min(d1, d2), diff = d1 - d2;
        if (diff > 0) {
            if (any_of(A.begin() + i1, A.begin() + i1 + diff, [](int x) { return x != 0; })) return 1;
            i1 += diff;
        } else if (diff < 0) {
            if (any_of(A.begin() + j1, A.begin() + j1 - diff, [](int x) { return x != 0; })) return -1;
            j1 -= diff;
        }
        for (int k = 0; k < length; ++k)
            if (A[i1 + k] != A[j1 + k]) return (A[i1 + k] > A[j1 + k]) ? 1 : -1;
        return 0;
    }
};
