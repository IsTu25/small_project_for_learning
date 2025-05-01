import tkinter as tk
from tkinter import messagebox


def check_winner(board, player):
    wins = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],
        [0, 3, 6], [1, 4, 7], [2, 5, 8],
        [0, 4, 8], [2, 4, 6]
    ]
    return any(all(board[i] == player for i in line) for line in wins)

def is_draw(board):
    return all(cell != -1 for cell in board)

def minimax(board, is_max):
    if check_winner(board, 1): return -1
    if check_winner(board, 0): return 1
    if is_draw(board): return 0

    best = -float('inf') if is_max else float('inf')
    for i in range(9):
        if board[i] == -1:
            board[i] = 0 if is_max else 1
            score = minimax(board, not is_max)
            board[i] = -1
            best = max(best, score) if is_max else min(best, score)
    return best

def best_move(board):
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


class TicTacToe:
    def __init__(self, root):
        self.root = root
        self.board = [-1]*9
        self.buttons = []
        self.build_gui()

    def build_gui(self):
        self.root.title("Tic Tac Toe - Unbeatable AI")
        for i in range(9):
            btn = tk.Button(self.root, text="", font="Helvetica 24", width=5, height=2,
                            command=lambda i=i: self.player_move(i))
            btn.grid(row=i//3, column=i%3)
            self.buttons.append(btn)

    def player_move(self, idx):
        if self.board[idx] != -1:
            return
        self.board[idx] = 1
        self.buttons[idx].config(text='X', state='disabled')
        if check_winner(self.board, 1):
            self.end_game("🎉 You win!")
            return
        if is_draw(self.board):
            self.end_game("It's a draw!")
            return

        self.root.after(500, self.ai_move)

    def ai_move(self):
        move = best_move(self.board)
        self.board[move] = 0
        self.buttons[move].config(text='O', state='disabled')
        if check_winner(self.board, 0):
            self.end_game("AI wins!")
        elif is_draw(self.board):
            self.end_game("It's a draw!")

    def end_game(self, msg):
        for b in self.buttons:
            b.config(state='disabled')
        messagebox.showinfo("Game Over", msg)

if __name__ == "__main__":
    root = tk.Tk()
    game = TicTacToe(root)
    root.mainloop()
