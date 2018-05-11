def valid(hash):
    for i in range(1, 10):
        if(hash[i] == 0):
            return 0
    return 1


def done_or_not(board):
    for i in [0, 3, 6]:
        for j in [0, 3, 6]:
            hash = [0] * 10
            for x in range(i, i + 3):
                for y in range(j, j + 3):
                    hash[board[x][y]] = 1
            if(valid(hash) == 0):
                return 'Try again!'

    for i in range(0, 9):
        hash = [0] * 10
        for j in range(0, 9):
            hash[board[i][j]] = 1
        if(valid(hash) == 0):
            return 'Try again!'

    for i in range(0, 10):
        hash = [0] * 10
        for j in range(0, 9):
            hash[board[j][i]] = 1
        if(valid(hash) == 0):
            return 'Try again!'

    return 'Finished!'

