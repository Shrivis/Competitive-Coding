from Chess.piece.base import Piece
from Chess.color import Color


class Bishop(Piece):
    def can_move(self, board, cell_from, cell_to):
        row_diff = abs(cell_from.row - cell_to.row)
        col_diff = abs(cell_from.col - cell_to.col)
        # bishops can only move diagonally so if row and col diff are not equal it is invalid move
        if row_diff == col_diff:
            # if there are any piece in between cell_from and cell_to, it is invalid move
            row_dir = 1 if cell_from.row<cell_to.row else -1
            col_dir = 1 if cell_from.col<cell_to.col else -1
            curr_row = cell_from.row
            curr_col = cell_from.col
            while(curr_row != cell_to.row and curr_col != cell_to.col):
                curr_row += row_dir
                curr_col += col_dir
                if board.get_piece(curr_row, curr_col) != None:
                    InvalidMoveError
            return True
        else:
            return False


    def get_initials(self):
        if self.color == Color.BLACK:
            return "\033[91m{}\033[0m".format('B')
        return 'B'
