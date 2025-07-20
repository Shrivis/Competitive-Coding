from Chess.piece.base import Piece
from Chess.color import Color


class Knight(Piece):
    def can_move(self, board, cell_from, cell_to):
        row_diff = abs(cell_to.row - cell_from.row)
        col_diff = abs(cell_to.col - cell_from.col)
        return (row_diff == 2 and col_diff == 1) or (row_diff == 1 and col_diff == 2)


    def get_initials(self):
        if self.color == Color.BLACK:
            return "\033[91m{}\033[0m".format('N')
        return 'N'