# 92ms, 53.29%; 18.3MB, 52.63%
from collections import defaultdict, deque
from itertools import count
from typing import List


class Twitter:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.users = defaultdict(set)  # { user : herself + followees }
        self.tweets = defaultdict(deque)  # { user : [tweets ordered by time] }
        self.timer = count(step=-1)  # timestamp

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        self.users.setdefault(userId, set())
        self.tweets.setdefault(userId, []).append((next(self.timer), tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed.
        Each item in the news feed must be posted by users who the user followed or by the user herself.
        Tweets must be ordered from most recent to least recent.
        """
        tmp = [y for x in self.users[userId] | {userId} for y in self.tweets[x]]
        return [x[1] for x in sorted(tmp, key=lambda x: x[0])[:10]]

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        self.users[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        self.users[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
