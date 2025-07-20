from Chess.piece.base import Piece
from Chess.color import Color


class King(Piece):
    def can_move(self, board, cell_from, cell_to):
        if abs(cell_from.row - cell_to.row) <= 1 and abs(cell_from.col - cell_to.col) <= 1:
            if cell_from.row == cell_to.row and cell_from.col == cell_to.col:
                return False
            return True
        return False


    def get_initials(self):
        if self.color == Color.BLACK:
            return "\033[91m{}\033[0m".format('K')
        return 'K'