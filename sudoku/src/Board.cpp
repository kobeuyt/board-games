#include "../include/Board.h"

namespace Sudoku
{
    Board::Board()
    {
        board = new std::map<Position, int>();
        tracker = new std::map<int, bool>();
        int i = 1;
        for (Position p : POS_ARR)
        {
            board->insert({p, 0});
            tracker->insert({i, false});
            i++;
        }
    }

    Board::~Board()
    {
        delete board;
        delete tracker;
    }

    void Board::ClearBoard()
    {
        for (Position p : POS_ARR)
        {
            board->at(p) = 0;
        }
    }

    void Board::SetValue(Position p, int n)
    {
        if (CheckNum(n))
        {
            board->at(p) = n;
        }
    }

    void Board::PopValue(Position p)
    {
        tracker->at(board->at(p)) = false;
        board->at(p) = 0;
    }

    bool Board::CheckNum(int n)
    {
        return !tracker->at(n);
    }

    std::array<int, 3> Board::GetSubset(Position p)
    {
        std::array<int, 3> subset;
        switch(p)
        {
            case Position::LEFT_COL:
                subset[0] = board->at(Position::TOP_LEFT);
                subset[1] = board->at(Position::MIDDLE_LEFT);
                subset[2] = board->at(Position::BOTTOM_LEFT);
                break;
            case Position::MID_COL:
                subset[0] = board->at(Position::TOP_MIDDLE);
                subset[1] = board->at(Position::CENTER);
                subset[2] = board->at(Position::BOTTOM_MIDDLE);
                break;
            case Position::RIGHT_COL:
                subset[0] = board->at(Position::TOP_RIGHT);
                subset[1] = board->at(Position::MIDDLE_RIGHT);
                subset[2] = board->at(Position::BOTTOM_RIGHT);
                break;
            case Position::TOP_ROW:
                subset[0] = board->at(Position::TOP_LEFT);
                subset[1] = board->at(Position::TOP_MIDDLE);
                subset[2] = board->at(Position::TOP_RIGHT);
                break;
            case Position::MID_ROW:
                subset[0] = board->at(Position::MIDDLE_LEFT);
                subset[1] = board->at(Position::CENTER);
                subset[2] = board->at(Position::MIDDLE_RIGHT);
                break;
            case Position::BOTTOM_ROW:
                subset[0] = board->at(Position::BOTTOM_LEFT);
                subset[1] = board->at(Position::BOTTOM_MIDDLE);
                subset[2] = board->at(Position::BOTTOM_RIGHT);
                break;
            default:
                // Should probably throw an error here
                break;
        }
        return subset;
    }

    int Board::CellsLeft()
    {
        return GetValidMoves().size();
    }

    std::vector<int> Board::GetValidMoves()
    {
        std::vector<int> moves;
        for(auto& tr : *tracker)
        {
            if (!tr.second)
            {
                moves.push_back(tr.first);
            }
        }
        return moves;
    }
}
