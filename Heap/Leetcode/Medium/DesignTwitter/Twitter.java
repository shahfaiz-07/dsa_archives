// https://leetcode.com/problems/design-twitter/
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

public class Twitter {
    class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    class Tuple {
        // int count, tweetId, uid, index
        int count, tweetId, uid, index;
        Tuple(int count, int tweetId, int uid, int index) {
            this.count = count;
            this.tweetId = tweetId;
            this.uid = uid;
            this.index = index;
        }
    }
    Map<Integer, HashSet<Integer>> followList; // followerId -> followeeId
    Map<Integer, List<Pair>> postList; // userId -> count(time), tweetId
    int count;
    public Twitter() {
        count = 0;
        followList = new HashMap<>();
        postList = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        postList.computeIfAbsent(userId, k -> new ArrayList<>()).add(new Pair(count, tweetId));
        count++;
    }
    
    public List<Integer> getNewsFeed(int userId) {
        Set<Integer> feedUserIds = followList.getOrDefault(userId, new HashSet<>());
        feedUserIds.add(userId);

        PriorityQueue<Tuple> maxHeap = new PriorityQueue<>((a, b) -> {
            return b.count - a.count;
        });
        for(int uid: feedUserIds) {
            List<Pair> posts = postList.getOrDefault(uid, new ArrayList<>());
            int postCount = posts.size();
            if(postCount != 0) {
                maxHeap.offer(new Tuple(posts.get(postCount - 1).first, posts.get(postCount - 1).second, uid, postCount - 1));
            }
        }

        int counter = 0;
        List<Integer> feed = new ArrayList<>();
        while(counter < 10 && !maxHeap.isEmpty()) {
            int tweetId = maxHeap.peek().tweetId;
            int uid = maxHeap.peek().uid;
            int index = maxHeap.peek().index;
            maxHeap.poll();
            feed.add(tweetId);
            if(index > 0) {
                List<Pair> posts = postList.get(uid);
                maxHeap.offer(new Tuple(posts.get(index - 1).first, posts.get(index - 1).second, uid, index - 1));
            }
            counter++;
        }
        return feed;
    }
    
    public void follow(int followerId, int followeeId) {
        followList.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        followList.computeIfPresent(followerId, (k, v) -> {
            v.remove(followeeId);
            return v;
        });
    }
}
