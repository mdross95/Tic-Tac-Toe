game:
	g++ -std=c++11 AIPlayer.cpp Board.cpp CreatePlayers.cpp HumanPlayer.cpp Game.cpp InputOutput.cpp main.cpp Player.cpp SetupGame.cpp Spot.cpp Validate.cpp -o game && ./game
test:
	g++ -std=c++11 AIPlayer.cpp Board.cpp CreatePlayers.cpp HumanPlayer.cpp Game.cpp InputOutput.cpp Player.cpp SetupGame.cpp Spot.cpp test.cpp Validate.cpp -o test && ./test
