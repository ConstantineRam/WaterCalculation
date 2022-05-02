#include "WaterContainerCalculator.h"

namespace WaterContainer
{
    bool Calculator::IsClosed(const int index)
    {
       return matrix.IsClosed(index);
    }
    bool Calculator::IsClosed(const int column, const int row)
    {
        return matrix.IsClosed(column, row);
    }

    void Calculator::StartFromCoords (const int column, const int row)
    {
        PushPointToStack(column, row);
        while (!pointStack.empty())
        {
            Point current = pointStack.top();
            pointStack.pop();
            ProcessPointOnMatrix(current);
        }
    }

    void Calculator::PushPointToStack(const int column, const int row)
    {
        if (!matrix.IsValidCoords(column, row))
        {return;}
        pointStack.push(matrix.CreatePoint(column, row));
    }

    void Calculator::ProcessPointOnMatrix(Point point)
    {
        if (point.IsWall())
        {
            return;
        }

        if (point.IsClosed())
        {
            return;
        }
        point.ClosePoint();

        PushPointToStack(point.Column-1, point.Row);
        PushPointToStack(point.Column+1, point.Row);
        PushPointToStack(point.Column, point.Row-1);
        PushPointToStack(point.Column, point.Row+1);
    }

    int Calculator::GetResult()
    {
        for (int i = matrix.FirstColumn(); i <= matrix.LastColumn(); i++)
        {
            StartFromCoords(i, matrix.FirstRow());
            StartFromCoords(i, matrix.LastRow());
        }

        for (int i = matrix.FirstRow(); i <= matrix.LastRow(); i++)
        {
            StartFromCoords(matrix.FirstColumn(), i);
            StartFromCoords(matrix.LastColumn(), i);
        }
        return matrix.GetOpenPointsCount();
    }
}
