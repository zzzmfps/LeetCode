// 420ms, 82.96%; 21.3MB, 33.33%
class Solution
{
public:
    int numSimilarGroups(vector<string> &A)
    {
        int res = 0;
        while (!A.empty()) {
            ++res;
            queue<string> que;
            que.push(A.back());
            A.pop_back();
            while (!que.empty()) {
                for (int i = A.size() - 1; i > -1; --i) {
                    if (checkSimilar(que.front(), A[i])) {
                        que.push(A[i]);
                        A.erase(A.begin() + i);
                    }
                }
                que.pop();
            }
        }
        return res;
    }

private:
    bool checkSimilar(const string &x, const string &y)
    {
        int count = 0;
        for (int i = 0, size = x.size(); i < size; ++i) {
            if (x[i] != y[i]) {
                ++count;
                if (count > 2) return false;
            }
        }
        return count < 3;
    }
};
