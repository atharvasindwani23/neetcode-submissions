class Twitter {

private:

        struct Tweet {
            int time;
            int tweetId;
            int uid;
            int idx;

            bool operator<(const Tweet& tweet) const {
                return (time < tweet.time);
            }
        };

public:

    int timestamp_ = 0;


    Twitter() {
        
    }
    
    unordered_map<int, unordered_set<int>> followers_; //mapping a user with all of its followers
    unordered_map<int, vector<pair<int,int>>> tweets_; //mapping a user with all of its tweets [when and which tweet]
    void postTweet(int userId, int tweetId) {
        tweets_[userId].push_back({timestamp_++, tweetId});
    }
    //time, tweetId, uid, idx 
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> latestTweets;
        followers_[userId].insert(userId);
        vector<int> feed;
        for (int follower: followers_[userId]) {
            if (tweets_.count(follower) && !tweets_[follower].empty()) {
                int idx = tweets_[follower].size() - 1;
                auto [time, tweet] = tweets_[follower][idx];
                latestTweets.push({time, tweet, follower, idx - 1});
            }
        }
        while (!latestTweets.empty() && feed.size() < 10) {
            auto [time, tweet, uid, idx] = latestTweets.top();
            latestTweets.pop();
            feed.push_back(tweet);

            if (idx >= 0) {
            int timestamp = tweets_[uid][idx].first;
            int tweet_id = tweets_[uid][idx].second;
            latestTweets.push({timestamp, tweet_id, uid, idx - 1});
        }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followers_[followerId].insert(followeeId);   
    }
    
    void unfollow(int followerId, int followeeId) {
        followers_[followerId].erase(followeeId);
    }
};
