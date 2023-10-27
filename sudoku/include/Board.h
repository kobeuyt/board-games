#pragma once

#include <array>
#include <map>
#include <string>
#include <vector>

#ifndef BOARD_H_
#define BOARD_H_

namespace Sudoku
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
        BOTTOM_RIGHT,
        LEFT_COL,
        MID_COL,
        RIGHT_COL,
        TOP_ROW,
        MID_ROW,
        BOTTOM_ROW
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

    const std::array<Position, 6> GRID_ARR = {
        Position::LEFT_COL,
        Position::MID_COL,
        Position::RIGHT_COL,
        Position::TOP_ROW,
        Position::MID_ROW,
        Position::BOTTOM_ROW
    };

    class Board
    {
        public:
            Board();
            virtual ~Board();

            void SetValue(Position p, int n);
            void PopValue(Position p);
            bool CheckNum(int n);
            std::array<int, 3> GetSubset(Position p);
            int CellsLeft();
            std::vector<int> GetValidMoves();
            void ClearBoard();
        private:
            std::map<Position, int> *board;
            std::map<int, bool> *tracker;
    };
}

#endif
