# Filler
The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program).
The game ends when the game piece cannot be placed anymore. Have fun!
- First you need to "make".
-------------------------------------------------------------------------------------
Usage: ./resources/filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]

   -t  --time		set timeout in second
   -q  --quiet		quiet mode
   -i  --interactive	interactive mode(default)
   -p1 --player1	use filler binary as a first player
   -p2 --player2	use filler binary as a second player
   -f  --file		use a map file (required)
   -s  --seed		use the seed number (initialization random) (man srand)
-------------------------------------------------------------------------------------
- My player is called "filler". Others: abanlin.filler, carli.filler, grati.filler, hcao.filler, superjeannot.filler.
- Player 'champely.filler' - doesnt play, with him you can see my tactics.
- If you are Player 1 your program will be represented by “o” and “O”. If you are Player 2, your program will be represented by “x” and “X”.
The lowercases (“x” or “o”) will highlight the piece last placed on the board. At the following turns, that same piece will be represented by the uppercase
letters (“X” or “O”), as it won’t be the piece last placed anymore.
- You will collect points each time you place a piece.
The Filler
• In this game, two players fight each other. They play one after the other.
• The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.
• The board is defined by X columns and N lines, it will then become X*N cells.
• At the beginning of each turn, you will receive your game piece.
• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells.
• To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).
• The shape must not exceed the dimensions of the board
• When the game starts, the board already contains one shape.
• The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed.
