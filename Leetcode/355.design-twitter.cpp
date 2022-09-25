/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (36.23%)
 * Likes:    2487
 * Dislikes: 325
 * Total Accepted:    102.7K
 * Total Submissions: 283K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n' +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user, and is able to see the 10 most recent tweets
 * in the user's news feed.
 *
 * Implement the Twitter class:
 *
 *
 * Twitter() Initializes your twitter object.
 * void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId
 * by the user userId. Each call to this function will be made with a unique
 * tweetId.
 * List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs
 * in the user's news feed. Each item in the news feed must be posted by users
 * who the user followed or by the user themself. Tweets must be ordered from
 * most recent to least recent.
 * void follow(int followerId, int followeeId) The user with ID followerId
 * started following the user with ID followeeId.
 * void unfollow(int followerId, int followeeId) The user with ID followerId
 * started unfollowing the user with ID followeeId.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
 * "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 * Output
 * [null, null, [5], null, null, [6, 5], null, [5]]
 *
 * Explanation
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5]. return [5]
 * twitter.follow(1, 2);    // User 1 follows user 2.
 * twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2
 * tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is
 * posted after tweet id 5.
 * twitter.unfollow(1, 2);  // User 1 unfollows user 2.
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5], since user 1 is no longer following user 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= userId, followerId, followeeId <= 500
 * 0 <= tweetId <= 10^4
 * All the tweets have unique IDs.
 * At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and
 * unfollow.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Twitter
{
public:
  map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> user;
  map<int, set<int>> connect;
  int time = 0;
  Twitter()
  {
  }

  void postTweet(int userId, int tweetId)
  {
    user[userId].push({time, tweetId}); // stores as (time,tweet) pair to min heap
    time++;
    if (user[userId].size() > 10) // keeping max 10 recents post of a user
      user[userId].pop();
  }
  void fun(priority_queue<pair<int, int>> &pq, int id) // add elements from min heap(id) to max heap(pq)
  {
    vector<vector<int>> temp;
    while (!user[id].empty())
    {
      int a = user[id].top().first;
      int b = user[id].top().second;
      user[id].pop();
      pq.push({a, b});
      temp.push_back({a, b});
    }
    for (auto x : temp)
    {
      user[id].push({x[0], x[1]});
    }
  }
  vector<int> getNewsFeed(int userId)
  {
    vector<int> v;
    priority_queue<pair<int, int>> pq;
    fun(pq, userId);               // user itself
    for (auto x : connect[userId]) // posts by followers
    {
      fun(pq, x);
    }
    int i = 0;
    while (!pq.empty())
    {
      v.push_back(pq.top().second);
      pq.pop();
      i++;
      if (i == 10)
        break;
    }
    return v;
  }

  void follow(int followerId, int followeeId)
  {
    connect[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    connect[followerId].erase(followeeId);
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
// @lc code=end
