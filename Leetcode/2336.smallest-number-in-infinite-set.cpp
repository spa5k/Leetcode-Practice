/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 *
 * https://leetcode.com/problems/smallest-number-in-infinite-set/description/
 *
 * algorithms
 * Medium (71.47%)
 * Likes:    237
 * Dislikes: 20
 * Total Accepted:    22.4K
 * Total Submissions: 31.3K
 * Testcase Example:  '["SmallestInfiniteSet","addBack","popSmallest","popSmallest","popSmallest","addBack","popSmallest","popSmallest","popSmallest"]\n' +
  '[[],[2],[],[],[],[1],[],[],[]]'
 *
 * You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
 *
 * Implement the SmallestInfiniteSet class:
 *
 *
 * SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain
 * all positive integers.
 * int popSmallest() Removes and returns the smallest integer contained in the
 * infinite set.
 * void addBack(int num) Adds a positive integer num back into the infinite
 * set, if it is not already in the infinite set.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest",
 * "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
 * [[], [2], [], [], [], [1], [], [], []]
 * Output
 * [null, null, 1, 2, 3, null, 1, 4, 5]
 *
 * Explanation
 * SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
 * smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change
 * is made.
 * smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest
 * number, and remove it from the set.
 * smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
 * smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
 * smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
 * smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to
 * the set and
 * ⁠                                  // is the smallest number, and remove it
 * from the set.
 * smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
 * smallestInfiniteSet.popSmallest(); // return 5, and remove it from the
 * set.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 1000
 * At most 1000 calls will be made in total to popSmallest and addBack.
 *
 *
 */
#include <headers.h>
// @lc code=start
class SmallestInfiniteSet
{
public:
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<bool> is_present;
  SmallestInfiniteSet()
  {
    int i = 1;
    while (i <= 1000)
    {
      pq.push(i);
      i++;
    }
    is_present = vector<bool>(1000, true);
  }

  int popSmallest()
  {
    int t = pq.top();
    pq.pop();
    is_present[t] = false;
    return t;
  }

  void addBack(int num)
  {
    if (!is_present[num])
    {
      pq.push(num);
      is_present[num] = true;
    };
    return;
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
