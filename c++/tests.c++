#include<gtest/gtest.h>
#include "interval.h"


class IntervalTests:public::testing::Test {

    protected:
        
        ClosedRange range1(10);
        ClosedRange range2(20, 30);
        ClosedRange range3(15, 25);

        OpenRange range4(15);
        OpenRange range5(25, 45);
        OpenRange range6(30, 40);

        SemiOpenRange range7(12);
        SemiOpenRange range8(1, 11);
        SemiOpenRange range9(30, 41);
};

TEST_F(IntervalTests, TestinggetStart) {

    /*ClosedRange range1(10);
    ClosedRange range2(20, 30);
    ClosedRange range3(15, 25);
    
    OpenRange range4(15);
    OpenRange range5(25, 45);
    OpenRange range6(30, 40);
    
    SemiOpenRange range7(12);
    SemiOpenRange range8(1, 11);
    SemiOpenRange range9(30, 41);*/

    ASSERT_EQ(0,  range1.getStart());
    ASSERT_EQ(20, range2.getStart());
    ASSERT_EQ(15, range3.getStart());
    ASSERT_EQ(0,  range4.getStart());
    ASSERT_EQ(26, range5.getStart());
    ASSERT_EQ(31, range6.getStart());
    ASSERT_EQ(0,  range7.getStart());
    ASSERT_EQ(1,  range8.getStart());
    ASSERT_EQ(30, range9.getStart());

}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
