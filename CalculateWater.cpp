#include "WaterContainerCalculator.h"

int CalcContainedWater(const int *p_data, int num_columns, int num_rows )
    {
        WaterContainer::Calculator calculator (p_data, num_columns, num_rows);
        return calculator.GetResult();
    };
