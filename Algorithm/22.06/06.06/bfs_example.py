# bfs -> 1 2 5 3 6 9 4 7 10 13 8 11 14 12 15 16
from collections import deque
from typing import List

# direction vectors
dRow = [0, 1, 0, -1]
dCol = [1, 0, -1, 0]


def isValidNode(vis, row, col):
    if (row < 0 or col < 0 or row >= 4 or col >= 4):
        return False
    if(vis[row][col]):
        return False
    return True


def BFS(grid: List[List[int]], vis: List[List[bool]], row: int, col: int) -> None:

    q = deque()

    q.append((row, col))
    vis[row][col] = True

    while len(q) > 0:
        cur = q.popleft()
        x, y = cur[0], cur[1]

        print(grid[x][y], end=" ")

        for i in range(4):
            nx = x + dRow[i]
            ny = y + dCol[i]
            if isValidNode(vis, nx, ny):
                q.append((nx, ny))
                vis[nx][ny] = True


if __name__ == "__main__":

    grid = [[1, 2, 3, 4],
            [5, 6, 7, 8],
            [9, 10, 11, 12],
            [13, 14, 15, 16]
            ]
    vis = [[False for _ in range(len(grid))] for _ in range(len(grid[0]))]
    BFS(grid, vis, 0, 0)
