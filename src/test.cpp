#include "../header/Experience.hpp"
#include "gtest/gtest.h"

TEST(ConstructorXP, GivenConstructorXP) {
    
    int level = 5;
    double exp = 100;  
    double expNext = 200;

    Experience *aExperience = new Experience(level,exp,expNext);

    EXPECT_EQ(aExperience->getLevel(), 5);
    EXPECT_EQ(aExperience->getEXP(), 100);
    EXPECT_EQ(aExperience->getNextEXP(), 200);
}

TEST(SETEXP, GetNextExp) {
    int level = 7;
    double exp = 500;  
    double expNext = 200;

    Experience *aExperience = new Experience(level,exp,expNext);

    aExperience->setNextEXP();
    EXPECT_EQ(aExperience->getNextEXP(), 325);
}

TEST(LEVELFunction, LEVELUP) {
    int level = 5;
    double exp = 272.8;  
    double expNext = 200;

    Experience *aExperience = new Experience(level,exp,expNext);
    
    ASSERT_TRUE(aExperience->updateLevel());
    EXPECT_EQ(aExperience->getLevel(), 6);
    EXPECT_EQ(aExperience->getEXP(), 72.800000000000011);
    EXPECT_EQ(aExperience->getNextEXP(), 187.5);
}

TEST(gainExperience, MONSTERded) {
    int level = 5;
    double exp = 400;  
    double expNext = 1000;

    Experience *aExperience = new Experience(level,exp,expNext);
    
    aExperience->gainExperience();
    EXPECT_EQ(aExperience->getEXP(), 500);
}

TEST(pointAssign, StatUpgrade) {
    int level = 5;
    int userInput = 1;
    double exp = 1000;  
    double expNext = 1000;

    Experience *aExperience = new Experience(level,exp,expNext);
    
    ASSERT_TRUE(aExperience->updateLevel());
    aExperience->pointAssign(userInput);
    EXPECT_EQ(aExperience->getHP(), 110);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}