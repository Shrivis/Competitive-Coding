from abc import ABC, abstractmethod
from Chess.color import Color

class Piece(ABC):
    def __init__(self, color: Color):
        self.color = color

    @abstractmethod
    def can_move(self, board, cell_from, cell_to):
        pass
    
    def get_color(self):
        return self.color