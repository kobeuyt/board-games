#include "Board.h"
#include <cstdio>
#include <string>

namespace TicTacToe
{
    Board::Board()
    {
        board = new std::map<Position, Player>();
        for (Position p : POS_ARR)
        {
            board->insert({p, Player::EMPTY});
        }
    }

    Board::~Board()
    {
        delete board;
    }

    void Board::ClearBoard()
    {
        for (Position p : POS_ARR)
        {
            board->at(p) = Player::EMPTY;
        }
    }

    void Board::Move(Position p, Player pl)
    {
        if (ValidMove(p))
        {
            board->at(p) = pl; 
        }
    }

    bool Board::ValidMove(Position p)
    {
        if (board->at(p) == Player::EMPTY)
        {
            return true;
        }
        return false;
    }

    int Board::MovesLeft()
    {
        return GetValidMoves().size();
    }

    std::vector<Position> Board::GetValidMoves()
    {
        std::vector<Position> validMoves = std::vector<Position>();

        for (Position p : POS_ARR)
        {
            if (ValidMove(p)) {validMoves.push_back(p);}
        }

        return validMoves;
    }

    Player Board::CheckWinner()
    {
        // Top row winner
        if (board->at(Position::TOP_LEFT) == board->at(Position::TOP_MIDDLE)
        && board->at(Position::TOP_MIDDLE) == board->at(Position::TOP_RIGHT))
        {
            return board->at(Position::TOP_LEFT);
        }
        // Middle row winner
        else if (board->at(Position::MIDDLE_LEFT) == board->at(Position::CENTER) 
        && board->at(Position::CENTER) == board->at(Position::MIDDLE_RIGHT))
        {
            return board->at(Position::MIDDLE_LEFT);
        }
        // Bottom row winner
        else if (board->at(Position::BOTTOM_LEFT) == board->at(Position::BOTTOM_MIDDLE) 
        && board->at(Position::BOTTOM_MIDDLE) == board->at(Position::BOTTOM_RIGHT))
        {
            return board->at(Position::BOTTOM_LEFT);
        }
        // Top left to bottom right diagonal winner
        else if (board->at(Position::TOP_LEFT) == board->at(Position::CENTER) 
        && board->at(Position::CENTER) == board->at(Position::BOTTOM_RIGHT))
        {
            return board->at(Position::TOP_LEFT);
        }
        // Top right to bottom left diagonal winner
        else if (board->at(Position::TOP_RIGHT) == board->at(Position::CENTER) 
        && board->at(Position::CENTER) == board->at(Position::BOTTOM_LEFT))
        {
            return board->at(Position::TOP_RIGHT);
        }
        // Left column winner
        else if (board->at(Position::TOP_LEFT) == board->at(Position::MIDDLE_LEFT) 
        && board->at(Position::MIDDLE_LEFT) == board->at(Position::BOTTOM_LEFT))
        {
            return board->at(Position::TOP_LEFT);
        }
        // Middle column winner
        else if (board->at(Position::TOP_MIDDLE) == board->at(Position::CENTER) 
        && board->at(Position::CENTER) == board->at(Position::BOTTOM_MIDDLE))
        {
            return board->at(Position::TOP_MIDDLE);
        }
        // Right column winner
        else if (board->at(Position::TOP_RIGHT) == board->at(Position::MIDDLE_RIGHT) 
        && board->at(Position::MIDDLE_RIGHT) == board->at(Position::BOTTOM_RIGHT))
        {
            return board->at(Position::TOP_RIGHT);
        }
        else
        {
            return Player::EMPTY;
        }
    }

    void Board::PrintBoard()
    {
        std::printf("\n");
        std::printf("     |     |     \n");
        std::printf("  %c  |  %c  |  %c  \n", PLAYER_CHAR.at(board->at(Position::TOP_LEFT)), PLAYER_CHAR.at(board->at(Position::TOP_MIDDLE)), PLAYER_CHAR.at(board->at(Position::TOP_RIGHT)));
        std::printf("_____|_____|_____\n");
        std::printf("     |     |     \n");
        std::printf("  %c  |  %c  |  %c  \n", PLAYER_CHAR.at(board->at(Position::MIDDLE_LEFT)), PLAYER_CHAR.at(board->at(Position::CENTER)), PLAYER_CHAR.at(board->at(Position::MIDDLE_RIGHT)));
        std::printf("_____|_____|_____\n");
        std::printf("     |     |     \n");
        std::printf("  %c  |  %c  |  %c  \n", PLAYER_CHAR.at(board->at(Position::BOTTOM_LEFT)), PLAYER_CHAR.at(board->at(Position::BOTTOM_MIDDLE)), PLAYER_CHAR.at(board->at(Position::BOTTOM_RIGHT)));
        std::printf("     |     |     \n");
        std::printf("\n");
    }
}

