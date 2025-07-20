from Chess.player import Player
from Chess.color import Color
from Chess.move import Move
from Chess.board import Board
from Chess.cell import Cell
from Chess.custom_exception import InvalidMoveError


class ChessGame:
    def __init__(self):
        self.board = Board()
        self.white_palyer = None
        self.black_player = None
        self.current_player  = None
    

    def set_player(self, first_player_name : str, second_player_name: str) -> None:
        # set white and black players and set the current player to white
        self.white_player = Player(name=first_player_name, color=Color.WHITE)
        self.black_player = Player(name=second_player_name, color=Color.BLACK)
        self.current_player = Color.WHITE
    

    def start(self) -> None:
        player1 = input('Enter first player name: ')
        player2 = input('Enter second player name: ')
        self.set_player(first_player_name=player1, second_player_name=player2)
        self.board.initialize_board()
        while not self.is_game_over():
            try:
                print(self.board)
                if self.current_player == Color.WHITE:
                    player = self.white_player
                else:
                    player = self.black_player
                print(f"{player.color.name}'s turn.")

                # take user input for next move
                player_move = self.get_player_move(player)

                # move the piece on the board
                self.board.move_piece(move=player_move)

                # switch player
                self.switch_turn()
            except Exception as e:
                print("\033[91m{}\033[0m".format(str(e)))
                print('***** Try again! *****')

        # Display game result
        self.display_result()

    

    def switch_turn(self) -> None:
        # check if current player is white
        if self.current_player == Color.WHITE:
            self.current_player = Color.BLACK
        else:
            # if current playser is black set it to white
            self.current_player = Color.WHITE
    

    def is_game_over(self) -> bool:
        # check for checkmate or stalemate condition
        if self.board.is_checkmate(Color.WHITE) or \
           self.board.is_checkmate(Color.BLACK) or \
           self.board.is_stalemate(Color.WHITE) or \
           self.board.is_stalemate(Color.BLACK):
           return True
        return False

    
    def get_player_move(self, player: Player) -> Move:
        # take user input for move
        user_input = input("Enter start and end position: ")
        user_input = list(map(int, user_input.strip().split(' ')))

        # check if user input is valid
        if len(user_input) != 4 or not all(isinstance(item, int) for item in user_input):
            raise ValueError("\033[91m{}\033[0m".format("Invalid input!"))

        # check if user input is out of bound
        self.board._is_out_of_bound(user_input[0], user_input[1])
        self.board._is_out_of_bound(user_input[0], user_input[1])
        
        # check if player is moving its own piece
        piece = self.board.get_piece(user_input[0], user_input[1])
        if piece is None or piece.color != player.color:
            raise ValueError("\033[91m{}\033[0m".format("Invalid piece selection!"))
        
        # check if player is capturing its own piece
        dest_piece = self.board.get_piece(user_input[2], user_input[3])
        if dest_piece and dest_piece.color == self.current_player:
            raise ValueError("\033[91m{}\033[0m".format("Cannot capture your own piece!"))

        return Move(Cell(user_input[0], user_input[1]), Cell(user_input[2], user_input[3]))

    

    def display_result() -> None:
        # check for stalemate to declare draw otherwise show current player won
        if self.board.is_stalemate(Color.WHITE) or self.board.is_stalemate(Color.BLACK):
            print('Draw')
        else:
            print(f'{self.current_player} Won')
    


if __name__ == "__main__":
    game = ChessGame()
    game.start()