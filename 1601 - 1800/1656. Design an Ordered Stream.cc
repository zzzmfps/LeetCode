// 92 ms, 95.39%; 81 MB, 95.71%
#include <bits/stdc++.h>
using namespace std;

class OrderedStream {
private:
    int lastReturned = 0;
    vector<string> stream;

public:
    OrderedStream(int n) {
        this->stream.resize(1 + n);
    }

    vector<string> insert(int idKey, const string &value) {
        stream[idKey] = value;
        if (idKey != 1 + this->lastReturned) return vector<string>();
        int i = idKey, j = idKey;
        while (j < this->stream.size() && !this->stream[j].empty()) ++j;
        this->lastReturned = j - 1;
        return vector<string>(this->stream.begin() + i, this->stream.begin() + j);
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
