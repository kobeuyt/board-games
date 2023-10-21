#include "Board.h"
#include <iostream>
#include <random>
#include <cstdlib>

using namespace TicTacToe;

Player Play(Board* t3board, Player starter, bool verbose=false)
{
    std::vector<Position> availableMoves = std::vector<Position>();
    int move;

    while (t3board->MovesLeft() > 0 && t3board->CheckWinner() == Player::EMPTY)
    {
        availableMoves = t3board->GetValidMoves();
        move = std::rand() % availableMoves.size();
        t3board->Move(availableMoves[move], starter);
        if (verbose)
        {
            t3board->PrintBoard();
        }

        switch (starter)
        {
            case Player::X:
                starter = Player::O;
                break;
            case Player::O:
                starter = Player::X;
                break;
            default:
                break;
        }
    }

    if (verbose)
    {
        if (t3board->CheckWinner() == Player::EMPTY)
        {
            std::cout << "The game ended in a draw." << std::endl;
        }
        else
        {
            std::cout << "The winner is Player " << PLAYER_CHAR.at(t3board->CheckWinner()) << "!" << std::endl;
        }
    }

    return t3board->CheckWinner();
}

void Simulate(Board* t3Board, Player player, int trials, bool verbose=false)
{
    int n = 0, xWins = 0, oWins = 0;
    Player winner;
    std::srand(std::time(0));

    while (n < trials)
    {
        winner = Play(t3Board, player, verbose);
        t3Board->ClearBoard();

        if (winner == Player::X)
        {
            xWins++;
        }
        else if(winner == Player::O)
        {
            oWins++;
        }

        switch (player)
        {
            case Player::X:
                player = Player::O;
                break;
            case Player::O:
                player = Player::X;
                break;
            default:
                break;
        }
        n++;
    }

    std::cout << "Number of Tic-Tac-Toe Games Played: " << trials
              << "\n\nX won " << xWins << " times."
              << "\nO won " << oWins << " times.\n"
              << trials - (oWins + xWins) << " tie games."
              << std::endl;
}

int main(int argc, char *argv[])
{
    Board* t3board = new Board();
    Player first = Player::X;
    bool verbose = true;

    if (argc > 1)
    {
        try
        {
            if (argc > 2) {verbose = std::strcmp("-v", argv[2]);}
            Simulate(t3board, first, std::stoi(argv[1]), !verbose);
        }
        catch(const std::invalid_argument e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        Simulate(t3board, first, 1, true);
    }

    return 0;
}
