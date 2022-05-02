#include "Storage.h"
#include "Point.h"
#include <vector>
#include <stack>
#ifndef PIO_WATERCONTAINERCALCULATOR_H
#define PIO_WATERCONTAINERCALCULATOR_H

class WaterCalculatorTest;
namespace WaterContainer
{

    class Calculator
    {
        friend WaterCalculatorTest;
    private:
        Storage matrix;

        std::stack<Point> pointStack;
        void StartFromCoords (const int column, const int row);
        void ProcessPointOnMatrix (Point point);
        void PushPointToStack ( const int column, const int row);

        bool IsClosed (const int index);
        bool IsClosed (const int column, const int row);

        bool IsProvidedDataLegit ();
    public:

        Calculator(const int *p_data, const int num_columns, const int num_rows
        ) : matrix(p_data, num_columns, num_rows)
        {
            if (num_rows < 2)
                {throw std::invalid_argument("num_row is too small.");}

            if (num_columns < 2)
                {throw std::invalid_argument("num_columns is too small.");}
        }

        int GetResult ();
    };
}




#endif //PIO_WATERCONTAINERCALCULATOR_H
