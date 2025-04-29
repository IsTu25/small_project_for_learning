def printBord(x, z):
    def mark(i): return 'X' if x[i] else ('O' if z[i] else i)
    print(f"{mark(0)} | {mark(1)} | {mark(2)}")
    print("--+---+--")
    print(f"{mark(3)} | {mark(4)} | {mark(5)}")
    print("--+---+--")
    print(f"{mark(6)} | {mark(7)} | {mark(8)}")

def check_winner(board, player):
    win_states = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  
        [0, 4, 8], [2, 4, 6]              
    ]
    return any(all(board[i] == player for i in state) for state in win_states)

def is_draw(board):
    return all(cell != -1 for cell in board)

def minimax(board, is_maximizing):
    if check_winner(board, 1): return -1 
    if check_winner(board, 0): return 1   
    if is_draw(board): return 0

    if is_maximizing:
        best = -float('inf')
        for i in range(9):
            if board[i] == -1:
                board[i] = 0
                best = max(best, minimax(board, False))
                board[i] = -1
        return best
    else:
        best = float('inf')
        for i in range(9):
            if board[i] == -1:
                board[i] = 1
                best = min(best, minimax(board, True))
                board[i] = -1
        return best

def best_move(x, y):
    board = [-1]*9
    for i in range(9):
        if x[i]: board[i] = 1
        elif y[i]: board[i] = 0

    best_score = -float('inf')
    move = -1
    for i in range(9):
        if board[i] == -1:
            board[i] = 0
            score = minimax(board, False)
            board[i] = -1
            if score > best_score:
                best_score = score
                move = i
    return move

if __name__ == '__main__':
    x = [0]*9
    y = [0]*9
    turn = 1
    print("Welcome to Tic Tac Toe (You vs. Unbeatable AI)")
    print("You are X and the AI is O")

    while True:
        printBord(x, y)
        if turn == 1:
            move = int(input("Your move (0–8): "))
            if move < 0 or move > 8 or x[move] or y[move]:
                print("Invalid move. Try again.")
                continue
            x[move] = 1
            if check_winner([1 if x[i] else (0 if y[i] else -1) for i in range(9)], 1):
                printBord(x, y)
                print("🎉 You win!")
                break
        else:
            print("AI is thinking...")
            move = best_move(x, y)
            y[move] = 1
            print(f"AI chose position {move}")
            if check_winner([1 if x[i] else (0 if y[i] else -1) for i in range(9)], 0):
                printBord(x, y)
                print("AI wins!")
                break

        if all(x[i] or y[i] for i in range(9)):
            printBord(x, y)
            print("It's a draw!")
            break

        turn = 3 - turn
