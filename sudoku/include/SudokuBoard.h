#pragma once

#include "Board.h"

#ifndef SUDOKU_BOARD_H_
#define SUDOKU_BOARD_H_

namespace Sudoku
{
    enum class RowCol
    {
        ROW1,
        ROW2,
        ROW3,
        ROW4,
        ROW5,
        ROW6,
        ROW7,
        ROW8,
        ROW9,
        COL1,
        COL2,
        COL3,
        COL4,
        COL5,
        COL6,
        COL7,
        COL8,
        COL9,
    };

    class SudokuBoard
    {
        public:
            SudokuBoard();
            virtual ~SudokuBoard();

            void SetValue(Position grid, Position cell, int n);
            void PopValue(Position grid, Position cell);
            std::array<int, 3> GetSubset(Position row, Position col);
            int CellsLeft();
            std::vector<int> GetValidMoves();
            void ClearBoard();
        private:
            std::map<Position, Board*> *sudoBoard;
            std::map<Board, bool> *sudoTracker;
    };
}

#endif