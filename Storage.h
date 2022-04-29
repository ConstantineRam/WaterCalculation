//
// Created by const on 4/28/2022.
//

#ifndef PIO_STORAGE_H
#define PIO_STORAGE_H

#include <vector>
#include "Point.h"
namespace WaterContainer {


// Assuming its contiguous two-dimensional, Row-major array of signed integers. :-)
// For real product we'd better use spun to begin with.
    class Storage final : public StorageInterface
            {
    private:
        const int *_array;
        const int numColumns;
        const int numRows;

        std::vector<bool> result;

        int ToIndex(const int column, const int row);

    public:
        const int FirstColumn () const;
        const int LastColumn () const;
        const int FirstRow () const;
        const int LastRow () const;


        Storage(const int *p_data, const int num_columns, const int num_rows) : _array(p_data),
                                                                                numColumns(num_columns),
                                                                                numRows(num_rows),
                                                                                result(num_columns * num_rows) {
        }

        Point CreatePoint (const int column, const int row);
        bool IsValidCoords(const int column, int row);

        void
        WithExistingPoint(const int column, const int row, void (*OnSuccess)(Point), void (*OnFailure)() = nullptr);

        int ElementAt(const int column, int row);
        int ElementAt(int index);

        void ClosePoint (const Point* point);
        bool IsClosed (const Point* point);
        bool IsClosed (const int index);
        bool IsClosed (const int column, int row);
        int GetOpenPointsCount ();

    };

}
#endif //PIO_STORAGE_H
