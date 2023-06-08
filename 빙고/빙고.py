def solution(board, nums):
    answer = 0
    map = [[0]*len(board) for _ in range(len(board[0]))]
    nums = set(nums)
    cnt = len(board)
    # print(map)
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] in nums:
                map[i][j] = 1
    answer += len([i for i in map if sum(i) == cnt])
    answer += len([i for i in zip(*map) if sum(i) == cnt])
    answer += int(sum(map[i][i] for i in range(cnt)) == cnt)
    answer += int(sum(map[cnt-i-1][i] for i in range(cnt)) == cnt)
        
    return answer