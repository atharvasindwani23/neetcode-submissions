class Twitter {
public:
    int timestamp;
    //userId -> {{timestamps, tweetId}}
    //userId -> {followerIds}
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        // ++timestamp so each new tweet gets a strictly higher value than all previous
        tweets[userId].push_back({++timestamp, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);

        // Max-heap: highest timestamp = most recent, popped first
        priority_queue<tuple<int,int,int,int>> maxHeap;

        for (int f : following[userId]) {
            if (tweets.count(f) && !tweets[f].empty()) { //if a particular follower has tweeted
                int idx = tweets[f].size() - 1; //collect the last tweet they sent
                auto [time, id] = tweets[f][idx]; //the last tweet sent by the user was at time and had an id of id
                maxHeap.push({time, id, f, idx - 1}); //pushing it into the maxheap 
            }
        }

        vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            auto [time, tweetId, uid, nextIdx] = maxHeap.top();
            maxHeap.pop();
            feed.push_back(tweetId);
            if (nextIdx >= 0) {
                auto [t, id] = tweets[uid][nextIdx];
                maxHeap.push({t, id, uid, nextIdx - 1});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};