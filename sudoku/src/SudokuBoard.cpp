#include "SudokuBoard.h"

namespace Sudoku
{
    SudokuBoard::SudokuBoard()
    {
        sudoBoard = new std::map<Position, Board*>();
        for (Position p : POS_ARR)
        {
            sudoBoard->insert({p, new Board()});
        }
    }

    SudokuBoard::~SudokuBoard()
    {
        delete sudoBoard;
    }

    void SudokuBoard::SetValue(Position grid, Position cell, int n)
    {
        // do stuff
    }

    void SudokuBoard::PopValue(Position grid, Position cell)
    {
        sudoBoard->at(grid)->PopValue(cell);
    }

    std::array<int, 3> SudokuBoard::GetSubset(RowCol rc) 
    {
        std::vector<int> subset;
        switch(rc)
        {
            case RowCol::ROW1:
                subset.insert(std::end(subset), std::begin(sudoBoard->at(Position::TOP_LEFT)->GetSubset(Position::TOP_ROW)),
                std::end(sudoBoard->at(Position::TOP_LEFT)->GetSubset(Position::TOP_ROW)));
                subset.insert(std::end(subset), std::begin(sudoBoard->at(Position::TOP_MIDDLE)->GetSubset(Position::TOP_ROW)),
                std::end(sudoBoard->at(Position::TOP_MIDDLE)->GetSubset(Position::TOP_ROW)));
                subset.insert(std::end(subset), std::begin(sudoBoard->at(Position::TOP_LEFT)->GetSubset(Position::TOP_ROW)),
                std::end(sudoBoard->at(Position::TOP_RIGHT)->GetSubset(Position::TOP_ROW)));
                break;
            default:
                // Should probably throw an error here
                break;
        }
        return subset;
    }
}