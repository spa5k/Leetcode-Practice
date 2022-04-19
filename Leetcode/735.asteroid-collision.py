#
# @lc app=leetcode id=735 lang=python3
#
# [735] Asteroid Collision
#
# https://leetcode.com/problems/asteroid-collision/description/
#
# algorithms
# Medium (44.38%)
# Likes:    3417
# Dislikes: 268
# Total Accepted:    193.1K
# Total Submissions: 435.1K
# Testcase Example:  '[5,10,-5]'
#
# We are given an array asteroids of integers representing asteroids in a row.
#
# For each asteroid, the absolute value represents its size, and the sign
# represents its direction (positive meaning right, negative meaning left).
# Each asteroid moves at the same speed.
#
# Find out the state of the asteroids after all collisions. If two asteroids
# meet, the smaller one will explode. If both are the same size, both will
# explode. Two asteroids moving in the same direction will never meet.
#
#
# Example 1:
#
#
# Input: asteroids = [5,10,-5]
# Output: [5,10]
# Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
# collide.
#
#
# Example 2:
#
#
# Input: asteroids = [8,-8]
# Output: []
# Explanation: The 8 and -8 collide exploding each other.
#
#
# Example 3:
#
#
# Input: asteroids = [10,2,-5]
# Output: [10]
# Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
# resulting in 10.
#
#
#
# Constraints:
#
#
# 2 <= asteroids.length <= 10^4
# -1000 <= asteroids[i] <= 1000
# asteroids[i] != 0
#
#
#

# @lc code=start
from typing import List


class Solution(object):
    def asteroidCollision(self, asteroids):
        res = []
        for asteroid in asteroids:
            while len(res) and asteroid < 0 and res[-1] > 0:
                if res[-1] == -asteroid:
                    res.pop()
                    break
                elif res[-1] < -asteroid:
                    res.pop()
                    continue
                elif res[-1] > -asteroid:
                    break
            else:
                res.append(asteroid)
        return res


print(Solution.asteroidCollision(Solution, [8, -8, 1, 2, 232, 4, -12]))

# @lc code=end
