// https://leetcode.com/problems/design-twitter/
#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    unordered_map<int, unordered_set<int>> followerList; // following list
    unordered_map<int, vector<pair<int, int>>> postList; // userId - count(time), tweedId
    int count;

public:
    Twitter()
    {
        count = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        postList[userId].push_back({count, tweetId});
        count++;
    }

    vector<int> getNewsFeed(int userId)
    {
        unordered_set<int> feedUserId = followerList[userId];
        feedUserId.insert(userId);
        // the last post is the most recent post for a user
        // but the most recent post will be based in the count
        // max heap should be based in count - first element of postList
        // I also have to store the current array(based on feedUserId), the index
        auto cmp = [](vector<int> &a, vector<int> &b)
        { return a[0] < b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap;
        for (int uid : feedUserId)
        {
            vector<pair<int, int>> posts = postList[uid];
            int postCount = posts.size(); // count and tweetId - pair
            if (postCount)
            {
                maxHeap.push({posts[postCount - 1].first, posts[postCount - 1].second, uid, postCount - 1}); // count(for maxHeap), tweetId, uid to identify the array, index to traverse back
            }
        }

        int counter = 0;
        vector<int> feed;
        while (counter < 10 && !maxHeap.empty())
        {
            int tweetId = maxHeap.top()[1];
            int uid = maxHeap.top()[2];
            int index = maxHeap.top()[3];
            maxHeap.pop();
            feed.emplace_back(tweetId);
            if (index)
            {
                vector<pair<int, int>> posts = postList[uid];
                maxHeap.push({posts[index - 1].first, posts[index - 1].second, uid, index - 1});
            }
            counter++;
        }

        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        followerList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followerList[followerId].erase(followeeId);
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