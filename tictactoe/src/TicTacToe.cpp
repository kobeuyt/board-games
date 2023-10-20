#include "Board.h"
#include <iostream>
#include <random>
#include <cstdlib>

using namespace games;

int main()
{
    Board t3board = Board();
    Player currentPlayer = Player::X;
    std::vector<Position> availableMoves = std::vector<Position>();
    int move;
    std::srand(std::time(NULL));

    while (t3board.MovesLeft() > 0 && t3board.CheckWinner() == Player::EMPTY)
    {
        availableMoves = t3board.GetValidMoves();
        move = std::rand() % availableMoves.size();
        t3board.Move(availableMoves[move], currentPlayer);
        t3board.PrintBoard();

        switch (currentPlayer)
        {
            case Player::X:
                currentPlayer = Player::O;
                break;
            case Player::O:
                currentPlayer = Player::X;
                break;
            default:
                break;
        }
    }

    currentPlayer = t3board.CheckWinner();
    if (currentPlayer == Player::EMPTY)
    {
        std::cout << "The game ended in a draw." << std::endl;
    }
    else
    {
        std::cout << "The winner is Player " << PLAYER_CHAR.at(currentPlayer) << "!" << std::endl;
    }

    return 0;
}