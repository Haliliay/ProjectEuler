#include "pch.h"
#include "../Problems1-20.h"


class Problem0008Test : public testing::Test {
protected:
	Problem0008 problem;
	void SetUp() override {

	}
};

TEST_F(Problem0008Test, ZeroAtTheEnd) {
	problem.largeDigitNumber = "2385629562347850";
	EXPECT_EQ(problem(1), 9);
	EXPECT_EQ(problem(2), 7 * 8);
	EXPECT_EQ(problem(4), 4 * 7 * 8 * 5);
}

TEST_F(Problem0008Test, MultipleZerosAtTheEnd) {
	problem.largeDigitNumber = "238562956234785000000";
	EXPECT_EQ(problem(1), 9);
	EXPECT_EQ(problem(2), 7 * 8);
	EXPECT_EQ(problem(4), 4 * 7 * 8 * 5);
}

TEST_F(Problem0008Test, ZeroAtTheBeginning) {
	problem.largeDigitNumber = "0238562956234785";
	EXPECT_EQ(problem(1), 9);
	EXPECT_EQ(problem(2), 7 * 8);
	EXPECT_EQ(problem(4), 4 * 7 * 8 * 5);
}

TEST_F(Problem0008Test, ZeroAtTheBeginningFew) {
	problem.largeDigitNumber = "2038562956234785";
	EXPECT_EQ(problem(1), 9);
	EXPECT_EQ(problem(2), 7 * 8);
	EXPECT_EQ(problem(4), 4 * 7 * 8 * 5);
}

TEST_F(Problem0008Test, ZerosInbetween) {
	problem.largeDigitNumber = "2385060290562304785";
	EXPECT_EQ(problem(1), 9);
	EXPECT_EQ(problem(2), 7 * 8);
	EXPECT_EQ(problem(4), 4 * 7 * 8 * 5);
}

TEST_F(Problem0008Test, ZerosInbetween2) {
	problem.largeDigitNumber = "0238506029050062304785000";
	EXPECT_EQ(problem(1), 9);
	EXPECT_EQ(problem(2), 7 * 8);
	EXPECT_EQ(problem(4), 4 * 7 * 8 * 5);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}