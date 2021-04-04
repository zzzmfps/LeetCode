// 28 ms, 99.84%; 18.9 MB, 8.33%
#include <bits/stdc++.h>
using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>> rectangle;
    vector<vector<int>> updates;

public:
    SubrectangleQueries(const vector<vector<int>> &rect) : rectangle(rect) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        this->updates.push_back({newValue, row1, col1, row2, col2});
    }

    int getValue(int row, int col) {
        for (auto it = this->updates.rbegin(); it != this->updates.rend(); ++it)
            if (row >= (*it)[1] && row <= (*it)[3] && col >= (*it)[2] && col <= (*it)[4]) return (*it)[0];
        return this->rectangle[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
