class InvalidMoveError(Exception):
    """Exception raised when a move is not valid on the board."""

    def __init__(self, message="Invalid move"):
        super().__init__(message)
