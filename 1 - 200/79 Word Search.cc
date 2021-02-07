// 68ms, 52.50%; 16.6MB, 51.47%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef vector<pair<int, int>> vpair;
    vector<vector<bool>> isVisited;
    pair<int, int> hint;

public:
    bool exist(const vector<vector<char>> &board, const string &word) {
        vpair start = find(board, word[0]);
        if (start.empty()) return false;
        int row = board.size(), col = board[0].size(), length = word.size();
        isVisited = vector<vector<bool>>(row, vector<bool>(col, false));
        stack<vpair> st;
        st.push(start);
        while (!st.empty()) {
            if (st.size() == length) return true;
            hint = st.top().back();
            isVisited[hint.first][hint.second] = true;
            vpair next_step = find(board, word[st.size()], true);
            if (!next_step.empty()) {
                st.push(move(next_step));
            } else {
                while (!st.empty() && st.top().size() == 1) {
                    int x = st.top()[0].first, y = st.top()[0].second;
                    st.pop(), isVisited[x][y] = false;
                }
                if (!st.empty()) {
                    int x = st.top().back().first, y = st.top().back().second;
                    st.top().pop_back(), isVisited[x][y] = false;
                }
            }
        }
        return false;
    }

private:
    vpair find(const vector<vector<char>> &board, char ch, bool useHint = false) {
        vpair ret;
        if (useHint) {
            int i = hint.first, j = hint.second;
            if (i && board[i - 1][j] == ch && !isVisited[i - 1][j]) ret.emplace_back(i - 1, j);
            if (j && board[i][j - 1] == ch && !isVisited[i][j - 1]) ret.emplace_back(i, j - 1);
            if (i + 1 < board.size() && board[i + 1][j] == ch && !isVisited[i + 1][j]) ret.emplace_back(i + 1, j);
            if (j + 1 < board[0].size() && board[i][j + 1] == ch && !isVisited[i][j + 1]) ret.emplace_back(i, j + 1);
        } else {
            for (int i = 0, row = board.size(); i < row; ++i)
                for (int j = 0, col = board[0].size(); j < col; ++j)
                    if (board[i][j] == ch) ret.emplace_back(i, j);
        }
        return ret;
    }
};
