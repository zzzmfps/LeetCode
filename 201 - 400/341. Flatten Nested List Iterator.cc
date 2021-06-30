// 18ms, 97.04%
#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class NestedIterator {
private:
    stack<vector<NestedInteger>::const_iterator> begins, ends;

public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        begins.push(nestedList.cbegin());
        ends.push(nestedList.cend());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (!begins.empty())
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                if (begins.top()->isInteger()) return true;
                auto &x = (begins.top()++)->getList(); // '&' is necessary
                begins.push(x.cbegin());
                ends.push(x.cend());
            }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
