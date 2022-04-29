//
// Created by const on 4/28/2022.
//

#include "Point.h"

namespace WaterContainer {

    void StorageInterface::ClosePoint (const Point* point){}
    bool StorageInterface::IsClosed (const Point* point) {return false;}

    void Point::ClosePoint()
    {
       myStorage->ClosePoint(this);
    }

    bool Point::IsClosed()
    {
       return myStorage->IsClosed(this);
    }

    bool Point::IsWall()
    {
        return Value == Wall;
    }

    bool Point::IsFlat()
    {
        return Value == Flat;
    }
} // WaterContainer