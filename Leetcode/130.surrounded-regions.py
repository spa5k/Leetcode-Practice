#
# @lc app=leetcode id=130 lang=python3
#
# [130] Surrounded Regions
#

# @lc code=start
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        length_of_board, length_of_row = len(board), len(board[0])

        def dfs(i, j):
            if i < 0 or i >= length_of_board or j < 0 or j >= length_of_row or board[i][j] != "O":
                return

            board[i][j] = "*"
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
            return

        for i in range(length_of_board):
            dfs(i, 0)
            dfs(i, length_of_row-1)

        for j in range(length_of_row):
            dfs(0, j)
            dfs(length_of_board-1, j)

        for i in range(length_of_board):
            for j in range(length_of_row):
                if board[i][j] == "*":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"
        return
# @lc code=end
