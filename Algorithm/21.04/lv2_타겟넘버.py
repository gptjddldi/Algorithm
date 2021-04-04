import copy
def solution(rows, columns, queries):
    answer = []

    # r,c 테두리, 각 회전에서 가장 작은 수를 리턴
    board = [[b+columns*a for b in range(1,columns+1)] for a in range(0,rows)]
    # 굿
    for x1,y1,x2,y2 in queries:
        board2 = copy.deepcopy(board)

        print(x1,y1,x2,y2)
        mini = 10001
        # x1~x2, y1~y2 값 이동, 최솟값 찾기
        # 이동? board[i][j] = board[i+1][j] or ...
        # i,j 의 위치에 따라 이동할 값이 달라짐
        # 4가지 각각의 경우 고려하면 되는듯
        # 행과 열을 구분해서 다시 써보자
        # x 좌표 : 열
        # y 좌표 : 행.. 아 처음에 잘좀 만들걸
        x1 -=1
        y1 -=1
        x2 -=1
        y2 -=1
        for x in range(x1,x2+1):
            for y in range(y1,y2+1):
                if x == x1 or x == x2 or y == y1 or y == y2:
                    mini = min(mini, board[x][y])
                    if x>=x1 and x<x2 and y==y1:
                        board[x][y] = board2[x+1][y]
                        # 오른쪽 이동
                    elif x==x2 and y>=y1 and y<y2:
                        # 아래로 이동
                        board[x][y] = board2[x][y+1]

                        

                    elif y==y2 and x>x1 and x<=x2:
                        # 왼쪽 이동
                        board[x][y] = board2[x-1][y]
                    elif x==x1 and y>y1 and y<=y2:
                        # 위로 이동
                        board[x][y] = board2[x][y-1]
        for i in range(len(board)):
            for j in range(len(board[i])):
                print(board[i][j], end=' ')
            print()
        answer.append(mini)
    return answer
print(solution(6,6,[[2,2,5,4],[3,3,6,6],[5,1,6,3]]))
# for i in range(1,5+1):
#     print(i)


# if x == x1 or x == x2 or y == y1 or y == y2:
#                     if x>=x1 and x<x2 and y==y1:
#                         board[x][y] = board[x+1][y]
#                         # 오른쪽 이동
                        
#                     elif x==x2 and y>=y1 and y<y2:
#                         # 아래로 이동
#                         board[x][y] = board[x][y+1]
#                     elif y==y2 and x>x1 and x<=x2:
#                         # 왼쪽 이동
#                         board[x][y] = board[x-1][y]
#                     elif x==x1 and y>y1 and y<=y2:
#                         # 위로 이동
#                         board[x][y] = board[x][y-1]