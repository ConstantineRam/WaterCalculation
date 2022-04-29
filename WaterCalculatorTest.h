#ifndef PIO_WATERCALCULATORTEST_H
#define PIO_WATERCALCULATORTEST_H


#include "WaterContainerCalculator.h"


class WaterCalculatorTest
{
private:
    WaterContainer::Calculator calculator;
public:

    WaterCalculatorTest(const int *p_data, const int num_columns, const int num_rows
    ) : calculator(p_data, num_columns, num_rows) {}

    void ProcessCoords (const int column, const int row);
    bool IsClosed (const int index);
    bool IsClosed (const int column, const int row);

    int StackCount ();
};

#endif //PIO_WATERCALCULATORTEST_H
