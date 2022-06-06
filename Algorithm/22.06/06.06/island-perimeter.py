# best sol
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        M, N, ret = len(grid), len(grid[0]), 0

        for i in range(M):
            for j in range(N):
                ret += 4*grid[i][j]
                if i > 0:
                    ret -= grid[i][j]*grid[i-1][j]
                if i < M-1:
                    ret -= grid[i][j]*grid[i+1][j]
                if j > 0:
                    ret -= grid[i][j]*grid[i][j-1]
                if j < N-1:
                    ret -= grid[i][j]*grid[i][j+1]
        return ret

# my sol


class Solution:

    def islandPerimeter(self, board: List[List[int]]) -> int:
        dirR = [0, 1, 0, -1]
        dirC = [1, 0, -1, 0]
        ret = 0
        M, N = len(board), len(board[0])
        vis = [[False for _ in range(N)] for _ in range(M)]
        q = deque()
        for i in range(M):
            for j in range(N):
                if board[i][j] and not vis[i][j]:
                    q.append((i, j))
                    vis[i][j] = True
                    ret = 4
                    break
            else:
                continue
            break

        while len(q) > 0:
            cur = q.popleft()
            x, y = cur[0], cur[1]
            print(x, y, sep=",", end=" / ")

            for i in range(4):
                nx = x + dirR[i]
                ny = y + dirC[i]
                # if isValidCell(board, vis, nx, ny, ret):
                if nx >= 0 and ny >= 0 and nx < M and ny < N and board[nx][ny]:
                    if vis[nx][ny]:
                        ret -= 1
                    else:
                        q.append((nx, ny))
                        vis[nx][ny] = True
                        ret += 3
        return ret
