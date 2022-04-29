#include <gtest/gtest.h>
#include "WaterContainerCalculator.h"
#include "Storage.h"
#include "WaterCalculatorTest.h"

#include "CalculateWater.h"

namespace
{
    class WaterTestFixture : public testing::Test
    {
    protected:
        void SetUp() override
        {

        }

        const int Matrix0[15] = {1, 1, 1, 1, 1,
                                 1, 0, 1, 0, 0,
                                 1, 1, 1, 0, 1
        };


        };
    }
const int Matrix1[] = {1, 1, 1, 1, 1,
                       1, 0, 1, 0, 0,
                       1, 1, 1, 0, 1
};
const int MatrixDifferent[] = {1, 2, 3, 4, 5,
                               6, 7, 8, 9, 10
};

const int MatrixOpen[] = {0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0,
};



const int MatrixTest0[] = {1, 1, 1, 1, 1,
                           1, 0, 1, 0, 0,
                           1, 0, 1, 0, 0,
                           1, 0, 1, 0, 1,
                           0, 1, 1, 0, 1,
                           1, 0, 1, 1, 0};

const int MatrixA[] = {1, 1, 1, 1, 1,
                          1, 0, 0, 0, 1,
                          1, 1, 1, 1, 1,
};

const int MatrixB[] = {1, 0, 1,
                       1, 0, 1,
                       1, 1, 1,
};

const int MatrixC[] = {0, 1, 0,
                       1, 0, 1,
                       0, 1, 0,
};
//
TEST (CasesFromPreInterviewTest, MatrixA)
{
    int containment = CalcContainedWater(MatrixA, 5, 3);
    ASSERT_EQ(containment, 3);
}

TEST (CasesFromPreInterviewTest, MatrixB)
{
    int containment = CalcContainedWater(MatrixB, 3, 3);
    ASSERT_EQ(containment, 0);
}

TEST (CasesFromPreInterviewTest, MatrixC)
{
    int containment = CalcContainedWater(MatrixC, 3, 3);
    ASSERT_EQ(containment, 1);
}

//-----

TEST(WaterCalculator, FullyOpenMatrixReturnsZero)
{
    WaterContainer::Calculator waterCalculator{MatrixOpen, 5, 3};
    int result = waterCalculator.GetResult();
    EXPECT_EQ(result, 0);
}


TEST(WaterCalculator, ReturnsCorrectValue)
{
    WaterContainer::Calculator waterCalculator{MatrixTest0, 5, 6};
    int result = waterCalculator.GetResult();
    EXPECT_EQ(result, 3);
}


TEST (Storage, AccessorChecksCoordsProperly)
{
    WaterContainer::Storage accessor (Matrix1, 5, 3);
    EXPECT_FALSE(accessor.IsValidCoords(-1, 1));
    EXPECT_FALSE(accessor.IsValidCoords(6, 1));
    EXPECT_FALSE(accessor.IsValidCoords(1, -5));
    EXPECT_FALSE(accessor.IsValidCoords(1, 99));
    EXPECT_FALSE(accessor.IsValidCoords(5, 3));

    EXPECT_TRUE(accessor.IsValidCoords(1, 1));
    EXPECT_TRUE(accessor.IsValidCoords(4, 2));
}
TEST (Storage, AccessorReturnsProperValue)
{
    WaterContainer::Storage accessor (MatrixDifferent, 5, 2);
    ASSERT_EQ(accessor.ElementAt(2,0), 3);
    ASSERT_EQ(accessor.ElementAt(2,1), 8);
    ASSERT_EQ(accessor.ElementAt(4,1), 10);
}
TEST (Storage, AccessorReturnsProperValueWith)
{
    WaterContainer::Storage accessor (MatrixDifferent, 5, 2);
    accessor.WithExistingPoint(2,2,
                               [](WaterContainer::Point p) { ASSERT_EQ(p.Value, 3); });

}

TEST (Storage, AccessorCallFailureInCaseOfWrongCoords) {
    WaterContainer::Storage accessor(MatrixDifferent, 5, 2);


    accessor.WithExistingPoint(999, 999,
                               [](WaterContainer::Point p) { FAIL(); },
                               []() { SUCCEED(); });
}

TEST (Storage, StorageReportsAllPointsToBeOpenedBeforeTestStarted) {
    WaterContainer::Storage accessor(Matrix1, 5, 3);
    ASSERT_EQ( accessor.GetOpenPointsCount(), 4);
}

TEST(WaterCalculator, SuccessfullyProcessesSingleDot)
{
    WaterCalculatorTest waterCalculator{MatrixTest0, 5, 3};
    waterCalculator.ProcessCoords(0, 0);
    ASSERT_TRUE(waterCalculator.IsClosed(0, 0));
}
