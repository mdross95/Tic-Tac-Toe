#include <vector>

#include "AIPlayer.hpp"
#include "Board.hpp"
#include "CreatePlayers.hpp"
#include "Game.hpp"
#include "InputOutput.hpp"
#include "HumanPlayer.hpp"
#include "Player.hpp"
#include "SetupGame.hpp"
#include "Spot.hpp"

using namespace std;

void testBoard()
{
    Board board;
    Player* p1ptr = new HumanPlayer('X', 1);
    Player* p2ptr = new HumanPlayer('O',1);

    //getBoardSize
    assert(board.getBoardSize() == 9);
    
    //takeSpot
    vector<Spot> testVec1(9, Spot());
    testVec1[0].setIsTaken();
    testVec1[0].setTakenBy(p1ptr);
    board.takeSpot(p1ptr, 0);
    assert(board.getBoardVec()[0] == testVec1[0]);
    assert(!(board.getBoardVec()[1] == testVec1[0]));
    
    //availableSpots
    board.takeSpot(p1ptr, 1);
    board.takeSpot(p2ptr, 2);
    board.takeSpot(p2ptr, 3);
    vector<Spot>testVec2;

    for (int i = 4; i < 9; i++)
    {
        testVec2.push_back(Spot(i, false, nullptr));
    }
    
    assert(testVec2.size() == board.availableSpots().size());
    
    for(int i = 0; i < 5; i++)
    {
        assert(testVec2[i].getLocation() == board.availableSpots()[i].getLocation());
    }

    //checkWin
    board = Board();
    assert(!board.checkWin(p1ptr));
    
    board.takeSpot(p1ptr, 0);
    board.takeSpot(p1ptr, 3);
    board.takeSpot(p1ptr, 6);
    assert(board.checkWin(p1ptr));
    
    board = Board();
    board.takeSpot(p1ptr, 1);
    board.takeSpot(p1ptr, 4);
    board.takeSpot(p1ptr, 7);
    assert(board.checkWin(p1ptr));
    
    board = Board();
    board.takeSpot(p1ptr, 2);
    board.takeSpot(p1ptr, 5);
    board.takeSpot(p1ptr, 8);
    assert(board.checkWin(p1ptr));
    
    board = Board();
    board.takeSpot(p1ptr, 0);
    board.takeSpot(p1ptr, 1);
    board.takeSpot(p1ptr, 2);
    assert(board.checkWin(p1ptr));
    
    board = Board();
    board.takeSpot(p1ptr, 3);
    board.takeSpot(p1ptr, 4);
    board.takeSpot(p1ptr, 5);
    assert(board.checkWin(p1ptr));
    
    board = Board();
    board.takeSpot(p1ptr, 6);
    board.takeSpot(p1ptr, 7);
    board.takeSpot(p1ptr, 8);
    assert(board.checkWin(p1ptr));
    
    board = Board();
    board.takeSpot(p1ptr, 0);
    board.takeSpot(p1ptr, 4);
    board.takeSpot(p1ptr, 8);
    assert(board.checkWin(p1ptr));
    
    board = Board();
    board.takeSpot(p1ptr, 2);
    board.takeSpot(p1ptr, 4);
    board.takeSpot(p1ptr, 6);
    assert(board.checkWin(p1ptr));
    
    //checkTie
    board = Board();
    assert(!board.checkTie());
    
    //checkTie checks for no available spots
    for (int i = 0; i < board.getBoardSize(); i++)
    {
        board.takeSpot(p1ptr, i);
    }

    assert(board.checkTie());
    
    delete p1ptr;
    delete p2ptr;
}

void testCreatePlayers()
{
    //createPlayers()
    CreatePlayers cp;
    Player* p1ptr;
    Player* p2ptr;
    Player* firstplayerptr;
    Player* secondplayerptr;
    
    cp.createPlayers(2, 'X', 'O', 1, p1ptr, p2ptr, firstplayerptr, secondplayerptr);
    
    assert(p1ptr->getSymbol() == 'X');
    assert(p2ptr->getSymbol() == 'O');
    assert(firstplayerptr == p1ptr);
    assert(secondplayerptr == p2ptr);
    assert(p1ptr->isHuman());
    assert(!p2ptr->isHuman());
    assert(p1ptr->getOtherPlayer() == p2ptr);
    assert(p2ptr->getOtherPlayer() == p1ptr);
    assert(p1ptr->getShouldPickRandomly() == false);
    assert(p2ptr->getShouldPickRandomly() == true);
}

void testInputOutput()
{
    InputOutput io;
    
    //checkTerminate
    string test = "notquit";
    assert(!io.checkTerminate(test));
    test = "quit";
    assert(io.checkTerminate(test));
}

void testPlayer()
{
    Board board;
    Player* p1ptr = new HumanPlayer('X', 1);
    Player* p2ptr = new AIPlayer('O',1);
    p1ptr->setOtherPlayer(p2ptr);
    p2ptr->setOtherPlayer(p1ptr);
    
    //isHuman
    assert(p1ptr->isHuman());
    assert(!p2ptr->isHuman());
    
    //getSymbol
    assert(p1ptr->getSymbol() == 'X');
    assert(p2ptr->getSymbol() == 'O');
    
    //getOtherPlayer/setOtherPlayer
    assert(p1ptr->getOtherPlayer() == p2ptr);
    assert(p2ptr->getOtherPlayer() == p1ptr);
    
    //get/setShouldPickRandomly
    assert(!p1ptr->getShouldPickRandomly());
    assert(p2ptr->getShouldPickRandomly());
    p2ptr->setShouldPickRandomly(false);
    assert(!p2ptr->getShouldPickRandomly());
    
    delete p1ptr;
    delete p2ptr;
}

void testSpot()
{
    Player* p1ptr = new HumanPlayer('X', 1);
    Player* p2ptr = new AIPlayer('O',1);
    Spot spot1(0, false, nullptr);
    Spot spot2(0, false, nullptr);
    
    //getIsTaken/setters
    assert(!spot1.getIsTaken());
    spot1.setIsTaken();
    spot1.setTakenBy(p1ptr);
    assert(spot1.getIsTaken());
    
    //getTakenBy/setters
    assert(spot2.getTakenBy() == nullptr);
    spot2.setIsTaken();
    spot2.setTakenBy(p2ptr);
    assert(spot2.getTakenBy() == p2ptr);
    
    //Spot==Spot
    assert(!(spot1==spot2));
    spot2.setTakenBy(p1ptr);
    assert(spot1==spot2);
    
    delete p1ptr;
    delete p2ptr;
}

void testValidate()
{
    Validate vldt;

    //validateFirstPlayer
    string firstPlayerInput = "wrong";
    assert(vldt.validateFirstPlayer(firstPlayerInput) == vldt.getFirstPlayerFailToken());
    firstPlayerInput = "3";
    assert(vldt.validateFirstPlayer(firstPlayerInput) == vldt.getFirstPlayerFailToken());
    firstPlayerInput = "1";
    assert(vldt.validateFirstPlayer(firstPlayerInput) == 1);
    firstPlayerInput = "2";
    assert(vldt.validateFirstPlayer(firstPlayerInput) == 2);

    //validateGameType
    string gameTypeInput = "wrong";
    assert(vldt.validateGameType(gameTypeInput) == vldt.getGameTypeFailToken());
    gameTypeInput = "4";
    assert(vldt.validateGameType(gameTypeInput) == vldt.getGameTypeFailToken());
    gameTypeInput = "1";
    assert(vldt.validateGameType(gameTypeInput) == 1);
    gameTypeInput = "2";
    assert(vldt.validateGameType(gameTypeInput) == 2);
    gameTypeInput = "3";
    assert(vldt.validateGameType(gameTypeInput) == 3);
    
    //validateSymbols
    string symbolsInput = "wrong";
    assert(vldt.validateSymbols(symbolsInput) == vldt.getSymbolFailToken());
    symbolsInput = "D >";
    assert(vldt.validateSymbols(symbolsInput) == vldt.getSymbolFailToken());
    symbolsInput = "D D";
    assert(vldt.validateSymbols(symbolsInput) == vldt.getSymbolFailToken());
    symbolsInput = "X O";
    assert(vldt.validateSymbols(symbolsInput) == std::make_pair('X', 'O'));
    
    Board board;
    Player* p1ptr = new HumanPlayer('X', 1);
    
    //validateMove
    string moveInput = "wrong";
    assert(vldt.validateMove(moveInput, board) == vldt.getMoveFailToken());
    moveInput = "100";
    assert(vldt.validateMove(moveInput, board) == vldt.getMoveFailToken());
    moveInput = "0";
    assert(vldt.validateMove(moveInput, board) == 0);
    board.takeSpot(p1ptr, 0);
    assert(vldt.validateMove(moveInput, board) == vldt.getMoveFailToken());
    
    delete p1ptr;
}

int main()
{
    testBoard();
    cout << "Board functions passed!" << endl;
    testCreatePlayers();
    cout << "CreatePlayers functions passed!" << endl;
    testInputOutput();
    cout << "InputOutput functions passed!" << endl;
    testPlayer(); //tests Player as well as AIPlayer and HumanPlayer
    cout << "Player functions passed!" << endl;
    testSpot();
    cout << "Spot function passed!" << endl;
    testValidate();
    cout << "Validate function passed!" << endl;
    cout << "ALL FUNCTIONS PASSED" << endl;
    return 0;
}
