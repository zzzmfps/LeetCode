// 56 ms, 43.16%; 18.2 MB, 28.41%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using Matrix = vector<vector<int>>;

public:
    int longestIncreasingPath(const Matrix &matrix) {
        size_t row = matrix.size(), col = matrix[0].size();
        Matrix visited(row, vector<int>(col, 0));

        Matrix incr(row, vector<int>(col));
        for (size_t i = 0; i < row; ++i)
            for (size_t j = 0; j < col; ++j) this->expandPath(matrix, visited, incr, i, j, greater<int>(), 1);
        Matrix decr(row, vector<int>(col));
        for (size_t i = 0; i < row; ++i)
            for (size_t j = 0; j < col; ++j) this->expandPath(matrix, visited, decr, i, j, less<int>(), 2);

        int res = 0;
        for (size_t i = 0; i < row; ++i)
            for (size_t j = 0; j < col; ++j) res = max(res, incr[i][j] + decr[i][j] - 1);
        return res;
    }

private:
    template <typename T>
    int expandPath(const Matrix &matrix, Matrix &visited, Matrix &lengths, int i, int j, T &&cmpRule, int mark) {
        if (visited[i][j] & mark) return lengths[i][j]; // 01 for incr, 10 for decr
        visited[i][j] |= mark;
        int length = 0;
        if (i > 0 && cmpRule(matrix[i][j], matrix[i - 1][j]))
            length = max(length, this->expandPath(matrix, visited, lengths, i - 1, j, cmpRule, mark));
        if (j > 0 && cmpRule(matrix[i][j], matrix[i][j - 1]))
            length = max(length, this->expandPath(matrix, visited, lengths, i, j - 1, cmpRule, mark));
        if (i + 1 < matrix.size() && cmpRule(matrix[i][j], matrix[i + 1][j]))
            length = max(length, this->expandPath(matrix, visited, lengths, i + 1, j, cmpRule, mark));
        if (j + 1 < matrix[0].size() && cmpRule(matrix[i][j], matrix[i][j + 1]))
            length = max(length, this->expandPath(matrix, visited, lengths, i, j + 1, cmpRule, mark));
        lengths[i][j] = ++length;
        return length;
    }
};
