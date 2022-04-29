#include "WaterContainerCalculator.h"

namespace WaterContainer
{
    bool Calculator::IsClosed(const int index)
    {
       return accessor.IsClosed(index);
    }
    bool Calculator::IsClosed(const int column, const int row)
    {
        return accessor.IsClosed(column, row);
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
        if (!accessor.IsValidCoords(column, row))
        {return;}
        pointStack.push(accessor.CreatePoint(column, row));
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
        for (int i = accessor.FirstColumn(); i <= accessor.LastColumn(); i++)
        {
            StartFromCoords(i, accessor.FirstRow());
            StartFromCoords(i, accessor.LastRow());
        }

        for (int i = accessor.FirstRow(); i <= accessor.LastRow(); i++)
        {
            StartFromCoords(accessor.FirstColumn(), i);
            StartFromCoords(accessor.LastColumn(), i);
        }
        return accessor.GetOpenPointsCount();
    }
}
