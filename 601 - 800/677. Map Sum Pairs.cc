// 4ms, 100.00%; 9.8MB, 63.83%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct Node {
    int val;
    bool isEnd;
    unordered_map<char, Node *> nxt;
    Node(int v = 0, bool ie = false) : val(v), isEnd(ie) {}
};

class MapSum {
private:
    Node *root;

public:
    MapSum() {
        root = new Node();
    }

    void insert(const string &key, int val) {
        Node *tmp = helper(key);
        Node *trav = root;
        if (tmp && tmp->isEnd) {
            int diff = tmp->val - val;
            for (auto k : key) {
                trav->nxt[k]->val -= diff;
                trav = trav->nxt[k];
            }
        } else {
            for (auto k : key) {
                if (trav->nxt.find(k) == trav->nxt.end()) {
                    trav->nxt[k] = new Node(val);
                } else {
                    trav->nxt[k]->val += val;
                }
                trav = trav->nxt[k];
            }
            trav->isEnd = true;
        }
    }

    int sum(const string &prefix) {
        Node *res = helper(prefix);
        return res ? res->val : 0;
    }

private:
    Node *helper(const string &x) {
        Node *trav = root;
        for (auto c : x) {
            if (trav->nxt.find(c) == trav->nxt.end()) return nullptr;
            trav = trav->nxt[c];
        }
        return trav;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
