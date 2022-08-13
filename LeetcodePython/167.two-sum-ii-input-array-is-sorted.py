class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1

        while left < right:
            sum_of_2 = numbers[left] + numbers[right]
            if sum_of_2 == target:
                return [left + 1, right + 1]
            elif sum_of_2 < target:
                left += 1
            else:
                right -= 1
