from Chess.piece.base import Piece
from Chess.color import Color


class Pawn(Piece):
    def can_move(self, board, cell_from, cell_to):
        row_diff = cell_to.row - cell_from.row
        col_diff = abs(cell_to.col - cell_from.col)

        if self.color == Color.WHITE:
            if row_diff == 1:
                if col_diff == 0 and board.get_piece(cell_to.row, cell_to.col) is None:
                    return True
                if col_diff == 1 and board.get_piece(cell_to.row, cell_to.col) is not None:
                   return True
            if row_diff == 2:
                if cell_from.row == 1 and board.get_piece(cell_to.row, cell_to.col) is None:
                    return True
            return False

        else:
            if row_diff == -1:
                if col_diff == 0 and board.get_piece(cell_to.row, cell_to.col) is None:
                    return True
                if col_diff == 1 and board.get_piece(cell_to.row, cell_to.col) is not None:
                   return True
            if row_diff == -2:
                if cell_from.row == 6 and board.get_piece(cell_to.row, cell_to.col) is None:
                    return True
            return False
    
    
    def get_initials(self):
        if self.color == Color.BLACK:
            return "\033[91m{}\033[0m".format('i')
        return 'i'