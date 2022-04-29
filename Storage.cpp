#include <iostream>
#include "Storage.h"
#include "Point.h"
#include<algorithm>
namespace WaterContainer
{
    void Storage::ClosePoint (const Point* point)
    {
        this->result[point->Index] = Closed;
    }
    bool Storage::IsClosed (const Point* point)
    {
        return this->IsClosed(point->Index);
    }

    bool Storage::IsClosed (const int index)
    {
        return this->result[index] == Closed;
    }
    bool Storage::IsClosed (const int column, int row)
    {
        return this->result[ToIndex(column, row)] == Closed;
    }

    bool Storage::IsValidCoords(const int column, int row) {
        return column >= 0 && column < numColumns && row >= 0 && row < numRows;
    }

    int Storage::GetOpenPointsCount()
    {
        int count = 0;
        int index = 0;
        std::for_each(result.begin(), result.end(), [this, &count, &index] (bool value)
        {
            if (value == Open)
            {
                if (this->ElementAt(index) == Flat)
                {count++;}
            }
            index++;
        });

        return count;
    }

    Point Storage::CreatePoint (const int column, const int row)
    {
        return Point (column, row, ToIndex(column, row), this->ElementAt(column, row), *this) ;
    }

    void Storage::WithExistingPoint(const int column, const int row, void (*OnSuccess)(Point), void (*OnFailure)())
    {
        if (!this->IsValidCoords(column, row))
        {
            OnFailure();
            return;
        }
        OnSuccess(CreatePoint(column, row));
    }

    int Storage::ElementAt(const int column, int row)
    {
        return ElementAt(ToIndex(column, row));
    }

    int Storage::ElementAt(int index)
    {
        return this->_array[index];
    }

    int Storage::ToIndex (const int column, const int row)
    {
        return column + (row * numColumns);
    }

    const int Storage::FirstColumn () const {return 0;};
    const int Storage::LastColumn () const {return numColumns -1;}
    const int Storage::FirstRow ()  const {return 0;}
    const int Storage::LastRow () const {return numRows -1;}
}