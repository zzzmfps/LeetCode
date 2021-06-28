// 52 ms, 78.03%; 20.3 MB, 60.42%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    class Counter {
    private:
        int *counts = new int[26]{};

    public:
        ~Counter() { delete[] counts; }

        static Counter getCounter(const string &str) {
            Counter c;
            for (auto &&s : str) ++c.counts[s - 97];
            return c;
        }

        friend bool operator<(const Counter &c1, const Counter &c2) {
            for (size_t i = 0; i < 26; ++i)
                if (c1.counts[i] > c2.counts[i]) return false;
            return true;
        }
    };

public:
    int countCharacters(const vector<string> &words, const string &chars) {
        Counter c = Counter::getCounter(chars);
        size_t res = 0;
        for (auto &&word : words)
            if (Counter::getCounter(word) < c) res += word.length();
        return static_cast<int>(res);
    }
};
