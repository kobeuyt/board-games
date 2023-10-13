#include "../include/Board.h"
#include <cstdio>
#include <string>

using namespace games;

Board::Board()
{
    board = new std::map<Position, Player>();
    for (Position p : POS_ARR)
    {
        board->at(p) = Player::EMPTY;
    }
}

Board::~Board()
{
    delete board;
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
    int emptySpaces = 0;

    for (Position p : POS_ARR)
    {
        if (board->at(p) == Player::EMPTY) {emptySpaces++;}    
    }

    return emptySpaces;
}

Player Board::CheckWinner()
{
    if (board->at(Position::TOP_LEFT) == board->at(Position::TOP_MIDDLE)
     && board->at(Position::TOP_MIDDLE) == board->at(Position::TOP_RIGHT))
    {
        return board->at(Position::TOP_LEFT);
    }
    else if (board->at(Position::MIDDLE_LEFT) == board->at(Position::CENTER) 
     && board->at(Position::CENTER) == board->at(Position::MIDDLE_RIGHT))
    {
        return board->at(Position::MIDDLE_LEFT);
    }
    else if (board->at(Position::BOTTOM_LEFT) == board->at(Position::BOTTOM_MIDDLE) 
     && board->at(Position::BOTTOM_MIDDLE) == board->at(Position::BOTTOM_RIGHT))
    {
        return board->at(Position::BOTTOM_LEFT);
    }
    else if (board->at(Position::MIDDLE_LEFT) == board->at(Position::CENTER) 
     && board->at(Position::CENTER) == board->at(Position::BOTTOM_RIGHT))
    {
        return board->at(Position::MIDDLE_LEFT);
    }
    else if (board->at(Position::MIDDLE_RIGHT) == board->at(Position::CENTER) 
     && board->at(Position::CENTER) == board->at(Position::BOTTOM_LEFT))
    {
        return board->at(Position::MIDDLE_RIGHT);
    }
    else if (board->at(Position::TOP_LEFT) == board->at(Position::MIDDLE_LEFT) 
     && board->at(Position::MIDDLE_LEFT) == board->at(Position::BOTTOM_LEFT))
    {
        return board->at(Position::TOP_LEFT);
    }
    else if (board->at(Position::TOP_MIDDLE) == board->at(Position::CENTER) 
     && board->at(Position::CENTER) == board->at(Position::BOTTOM_MIDDLE))
    {
        return board->at(Position::TOP_MIDDLE);
    }
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
    std::printf("     |     |     ");
    std::printf("  %c  |  %c  |  %c  ", PLAYER_CHAR.at(board->at(Position::TOP_LEFT)), PLAYER_CHAR.at(board->at(Position::TOP_MIDDLE)), PLAYER_CHAR.at(board->at(Position::TOP_RIGHT)));
    std::printf("_____|_____|_____");
    std::printf("     |     |     ");
    std::printf("  %c  |  %c  |  %c  ", PLAYER_CHAR.at(board->at(Position::MIDDLE_LEFT)), PLAYER_CHAR.at(board->at(Position::CENTER)), PLAYER_CHAR.at(board->at(Position::MIDDLE_RIGHT)));
    std::printf("_____|_____|_____");
    std::printf("     |     |     ");
    std::printf("  %c  |  %c  |  %c  ", PLAYER_CHAR.at(board->at(Position::BOTTOM_LEFT)), PLAYER_CHAR.at(board->at(Position::BOTTOM_MIDDLE)), PLAYER_CHAR.at(board->at(Position::BOTTOM_RIGHT)));
    std::printf("     |     |     ");
}