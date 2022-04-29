#include <gtest/gtest.h>
#include "WaterContainerCalculator.h"
#include "WaterCalculatorTest.h"

//WaterCalculatorTest
void WaterCalculatorTest::ProcessCoords (const int column, const int row)
{
    calculator.StartFromCoords(column, row);
}
bool WaterCalculatorTest::IsClosed (const int index)
{
    return calculator.IsClosed(index);
}

bool WaterCalculatorTest::IsClosed (const int column, const int row)
{
    return calculator.IsClosed(column, row);
}
int WaterCalculatorTest::StackCount ()
{
    return calculator.pointStack.size();
}





