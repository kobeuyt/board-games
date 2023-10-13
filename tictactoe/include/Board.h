#include <array>
#include <map>

#ifndef BOARD_H_
#define BOARD_H_

namespace games
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
            Player CheckWinner();
            void PrintBoard();
        private:
            std::map<Position, Player> *board;
    };
}

#endif