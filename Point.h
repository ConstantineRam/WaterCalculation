//
// Created by const on 4/28/2022.
//

#ifndef PIO_POINT_H
#define PIO_POINT_H



#include <iostream>


namespace WaterContainer {

class Point;
class StorageInterface
{
public:
    virtual void ClosePoint (const Point* point);
    virtual bool IsClosed (const Point* point);

};
    const int Wall = 1;
    const int Flat = 0;

    const bool Closed = true;
    const bool Open = false;

    class Point {
    private:
        StorageInterface *myStorage;
    public:
        const int Column;
        const int Row;
        const int Index;
        const int Value;

        bool IsClosed ();
        void ClosePoint();
        bool IsWall();
        bool IsFlat();

        Point(const int column, const int row, const int index, const int value, StorageInterface& storage) :
              Column(column), Row(row), Index(index), Value(value), myStorage(&storage)
        {
            if (myStorage == nullptr)
            {throw std::invalid_argument("Assigned storage is null or of a wrong type");}
        }
    };
} // WaterContainer

#endif //PIO_POINT_H
