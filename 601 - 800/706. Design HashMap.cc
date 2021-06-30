// 100ms, 99.94%; 45.9MB, 62.59%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class MyHashMap {
private:
    vector<vector<vector<int>>> myHashMap;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        myHashMap.resize(101);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int i, j, k;
        getIndex(key, i, j, k);
        if (myHashMap[i].empty()) myHashMap[i].resize(100);
        if (myHashMap[i][j].empty()) {
            myHashMap[i][j].resize(101, -1);
            myHashMap[i][j][0] = 0; // a counter of number of element inserted (!= -1)
        }
        if (myHashMap[i][j][k] == -1) myHashMap[i][j][0] += 1;
        myHashMap[i][j][k] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int i, j, k;
        getIndex(key, i, j, k);
        if (myHashMap[i].empty() || myHashMap[i][j].empty()) return -1;
        return myHashMap[i][j][k];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i, j, k;
        getIndex(key, i, j, k);
        if (!myHashMap[i].empty() && !myHashMap[i][j].empty() && myHashMap[i][j][k] >= 0) {
            if (myHashMap[i][j][0] == 1) {
                myHashMap[i][j].clear();
            } else {
                myHashMap[i][j][0] -= 1;
                myHashMap[i][j][k] = -1;
            }
        }
    }

private:
    void getIndex(int key, int &i, int &j, int &k) {
        i = key / 10000;
        j = key / 100 % 100;
        k = key % 100 + 1; // due to existence of counter
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
