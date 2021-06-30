// 60ms, 30.72%; 21MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    int timer = 0;
    unordered_map<int, unordered_set<int>> users;      // user, followees
    unordered_map<int, vector<pair<int, int>>> tweets; // user, (time, tweet)

public:
    /** Initialize your data structure here. */
    Twitter() {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timer++, tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by
     * users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> tmp(tweets[userId].begin(), tweets[userId].end());
        for (auto f : users[userId]) tmp.insert(tmp.end(), tweets[f].begin(), tweets[f].end());
        partial_sort(tmp.begin(), tmp.begin() + min(10, int(tmp.size())), tmp.end(),
                     [](const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; });
        vector<int> res;
        for (auto &p : tmp) {
            res.push_back(p.second);
            if (res.size() == 10) break;
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        users[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
