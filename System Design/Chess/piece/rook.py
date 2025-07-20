from Chess.piece.base import Piece
from Chess.color import Color


class Rook(Piece):
    def can_move(self, board, cell_from, cell_to):
        if cell_from.row == cell_to.row or cell_from.col == cell_to.col:
            if cell_from.row == cell_to.row:
                row_dir = 0
                col_dir = -1 if cell_from.col<cell_to.col else 1
            else:
                row_dir = -1 if cell_from.row<cell_to.row else 1
                col_dir = 0
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
            return "\033[91m{}\033[0m".format('R')
        return 'R'