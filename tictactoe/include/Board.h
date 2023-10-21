#pragma once

#include <array>
#include <map>
#include <string>
#include <vector>

#ifndef BOARD_H_
#define BOARD_H_

namespace TicTacToe
{
    enum class Position
    {
        TOP_LEFT,
        TOP_MIDDLE,
        TOP_RIGHT,
        MIDDLE_LEFT,
        CENTER,
        MIDDLE_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_MIDDLE,
        BOTTOM_RIGHT
    };

    enum class Player
    {
        X,
        O,
        EMPTY
    };

    const std::array<Position, 9> POS_ARR = {
        Position::TOP_LEFT,
        Position::TOP_MIDDLE,
        Position::TOP_RIGHT,
        Position::MIDDLE_LEFT,
        Position::CENTER,
        Position::MIDDLE_RIGHT,
        Position::BOTTOM_LEFT,
        Position::BOTTOM_MIDDLE,
        Position::BOTTOM_RIGHT
    };

    const std::map<Position, std::string> POS_STR = {
        {Position::TOP_LEFT, "TOP_LEFT"},
        {Position::TOP_MIDDLE, "TOP_MIDDLE"},
        {Position::TOP_RIGHT, "TOP_RIGHT"},
        {Position::MIDDLE_LEFT, "MIDDLE_LEFT"},
        {Position::CENTER, "CENTER"},
        {Position::MIDDLE_RIGHT, "MIDDLE_RIGHT"},
        {Position::BOTTOM_LEFT, "BOTTOM_LEFT"},
        {Position::BOTTOM_MIDDLE, "BOTTOM_MIDDLE"},
        {Position::BOTTOM_RIGHT, "BOTTOM_RIGHT"}
    };

    const std::map<Player, unsigned char> PLAYER_CHAR = {
        {Player::X, 'X'},
        {Player::O, 'O'},
        {Player::EMPTY, ' '}
    };

    class Board
    {
        public:
            Board();
            virtual ~Board();

            void Move(Position p, Player pl);
            bool ValidMove(Position p);
            int MovesLeft();
            std::vector<Position> GetValidMoves();
            Player CheckWinner();
            void PrintBoard();
            void ClearBoard();
        private:
            std::map<Position, Player> *board;
    };
}

#endif
