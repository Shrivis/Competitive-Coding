from Chess.cell import Cell
from Chess.piece.rook import Rook
from Chess.piece.knight import Knight
from Chess.piece.bishop import Bishop
from Chess.piece.queen import Queen
from Chess.piece.king import King
from Chess.piece.pawn import Pawn
from Chess.move import Move
from Chess.color import Color
from Chess.custom_exception import InvalidMoveError

class Board:
    def __init__(self):
        self.grid = [[Cell(row, col) for col in range(8)] for row in range(8)]


    def initialize_board(self):
        # Initialize white pieces
        self.grid[0][0].piece = Rook(Color.WHITE)
        self.grid[0][1].piece = Knight(Color.WHITE)
        self.grid[0][2].piece = Bishop(Color.WHITE)
        self.grid[0][3].piece = Queen(Color.WHITE)
        self.grid[0][4].piece = King(Color.WHITE)
        self.grid[0][5].piece = Bishop(Color.WHITE)
        self.grid[0][6].piece = Knight(Color.WHITE)
        self.grid[0][7].piece = Rook(Color.WHITE)
        for i in range(8):
            self.grid[1][i].piece = Pawn(Color.WHITE)

        # Initialize black pieces
        self.grid[7][0].piece = Rook(Color.BLACK)
        self.grid[7][1].piece = Knight(Color.BLACK)
        self.grid[7][2].piece = Bishop(Color.BLACK)
        self.grid[7][3].piece = Queen(Color.BLACK)
        self.grid[7][4].piece = King(Color.BLACK)
        self.grid[7][5].piece = Bishop(Color.BLACK)
        self.grid[7][6].piece = Knight(Color.BLACK)
        self.grid[7][7].piece = Rook(Color.BLACK)
        for i in range(8):
            self.grid[6][i].piece = Pawn(Color.BLACK)

    def _is_out_of_bound(self, row: int, col: int):
        if row < 0 or row > 8 < 8 or col < 0 or col > 8:
            raise InvalidMoveError

    def get_cell(self, row: int, col: int) -> Cell:
        self._is_out_of_bound(row, col)
        return self.grid[row][col]

    def move_piece(self, move: Move) -> bool:
        start = move.get_start()
        end = move.get_end()
        piece = self.get_piece(start.row, start.col)
        if piece:
            if piece.can_move(self, start, end):
                self.grid[end.row][end.col].piece = self.grid[start.row][start.col].piece
                self.grid[start.row][start.col].piece = None
                return True
        raise InvalidMoveError


    def get_piece(self, row: int, col: int):
        self._is_out_of_bound(row, col)
        return self.grid[row][col].piece


    def set_piece(self, row: int, col: int, piece) -> None:
        self._is_out_of_bound(row, col)
        self.grid[row][col] = piece


    def is_checkmate(self, color):
        return False


    def is_stalemate(self, color):
        return False


    def __repr__(self) -> str:
        board_repr = ""
        for row in range(7, -1, -1):
            board_repr += f"{row}| "
            board_repr += " | ".join([cell.piece.get_initials() if cell.piece else "." for cell in self.grid[row]]) + "\n"
        footer = "‾‾‾" + "‾‾‾".join([str(item) for item in range(8)]) + "‾‾‾" + "\n"
        # board_repr += "  " + "‾"*(len(footer)-2) + ""
        board_repr += footer
        return board_repr
