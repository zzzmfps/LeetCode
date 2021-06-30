// 4ms, 100.00%; 9.2MB, 55.29%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    int tinyIndex = -1;
    vector<string> tiny2Url;
    unordered_map<string, int> url2Tiny;

public:
    // Encodes a URL to a shortened URL.
    string encode(const string &longUrl) {
        tinyIndex += 1;
        tiny2Url.push_back(longUrl);
        url2Tiny[longUrl] = tinyIndex;
        return "http://tinyurl.com/" + to_string(tinyIndex);
    }

    // Decodes a shortened URL to its original URL.
    string decode(const string &shortUrl) {
        int idx = shortUrl.rfind('/') + 1;
        return tiny2Url[stoi(shortUrl.substr(idx))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
