#
# @lc app=leetcode id=703 lang=python3
#
# [703] Kth Largest Element in a Stream
#

# @lc code=start
import heapq


class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.minHeap=nums
        self.k=k
        heapq.heapify(self.minHeap)
        while len(self.minHeap) >k:
            heapq.heappop(self.minHeap)

    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap,val)

        if len(self.minHeap)>self.k:
          heapq.heappop(self.minHeap)
        return self.minHeap[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
# @lc code=end
