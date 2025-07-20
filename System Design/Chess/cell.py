from Chess.piece.base import Piece

class Cell:
    def __init__(self, row: int, col: int, piece: Piece = None):
        self.row = row
        self.col = col
        self.piece = piece
    
    
    def is_occupied(self):
        return True if self.piece else False
    

    def get_piece(self):
        return self.piece
    

    def set_picee(self, piece: Piece):
        self.piece = piece
    

    def get_row(self):
        return self.row
    

    def get_col(self):
        return self.col