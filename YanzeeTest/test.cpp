#include "pch.h"
#include "./../Yanzee/Yanzee.h"
#include "./../Yanzee/Yanzee.cpp"

TEST(TestCaseName, YanzeeNumbersTest) {
	Yanzee yan{};
	std::vector<int> var = { 1,2,3,4,5 };
	auto num = Combinations::Numbers;
	int yanRes = yan.round(var, num);
	ASSERT_TRUE(yanRes == 15);
}

TEST(TestCaseName, YanzeeIsPairTest) {
	Yanzee yan{};
	std::vector<int> var = { 1,2,3,4,5 };
	std::vector<int> var1 = { 1,2,2,4,5 };
	std::vector<int> var2 = { 1,2,3,4,4 };
	std::vector<int> var3 = { 1,2,3,5,5 };
	std::vector<int> var4 = { 1,2,5,5,5 };
	auto num = Combinations::Pair;
	int yanRes = yan.round(var, num);
	ASSERT_TRUE(yanRes == 0);

	yanRes = yan.round(var1, num);
	ASSERT_TRUE(yanRes == 4);

	yanRes = yan.round(var2, num);
	ASSERT_TRUE(yanRes == 8);

	yanRes = yan.round(var3, num);
	ASSERT_TRUE(yanRes == 10);

	yanRes = yan.round(var4, num);
	ASSERT_TRUE(yanRes == 10);
}
TEST(TestCaseName, YanzeeIsTwoPairTest) {
	Yanzee yan{};
	std::vector<int> var = { 1,2,2,4,4};
	std::vector<int> var1 = { 1,2,2,4,5 };
	std::vector<int> var2 = { 1,2,2,2,2 };
	std::vector<int> var3 = { 5,2,2,5,5 };
	std::vector<int> var4 = { 1,2,4,3,5 };
	auto num = Combinations::TwoPair;
	int yanRes = yan.round(var, num);
	ASSERT_EQ(yanRes, 12);

	yanRes = yan.round(var1, num);
	ASSERT_EQ(yanRes, 0);

	yanRes = yan.round(var2, num);
	ASSERT_EQ(yanRes, 8);

	yanRes = yan.round(var3, num);
	ASSERT_EQ(yanRes, 14);

	yanRes = yan.round(var4, num);
	ASSERT_EQ(yanRes, 0);
}

TEST(TestCaseName, YanzeeThreeOfKindTest) {
	Yanzee yan{};
	std::vector<int> var = { 1,2,2,2,4 };
	std::vector<int> var1 = { 4,2,2,4,4 };
	std::vector<int> var2 = { 1,2,2,2,2 };
	std::vector<int> var3 = { 1,1,5,5,1 };
	std::vector<int> var4 = { 2,2,4,4,5 };
	auto num = Combinations::ThreeOfKind;
	int yanRes = yan.round(var, num);
	ASSERT_EQ(yanRes, 6);

	yanRes = yan.round(var1, num);
	ASSERT_EQ(yanRes, 12);

	yanRes = yan.round(var2, num);
	ASSERT_EQ(yanRes, 6);

	yanRes = yan.round(var3, num);
	ASSERT_EQ(yanRes, 3);

	yanRes = yan.round(var4, num);
	ASSERT_EQ(yanRes, 0);
}

TEST(TestCaseName, YanzeeFourOfKindTest) {
	Yanzee yan{};
	std::vector<int> var = { 1,2,2,2,2 };
	std::vector<int> var1 = { 4,4,2,4,4 };
	std::vector<int> var2 = { 1,2,3,2,2 };
	std::vector<int> var3 = { 1,1,5,5,1 };
	std::vector<int> var4 = { 2,2,4,4,5 };
	auto num = Combinations::FourOfKind;
	int yanRes = yan.round(var, num);
	ASSERT_EQ(yanRes, 8);

	yanRes = yan.round(var1, num);
	ASSERT_EQ(yanRes, 16);

	yanRes = yan.round(var2, num);
	ASSERT_EQ(yanRes, 0);

	yanRes = yan.round(var3, num);
	ASSERT_EQ(yanRes, 0);

	yanRes = yan.round(var4, num);
	ASSERT_EQ(yanRes, 0);
}

TEST(TestCaseName, YanzeeSmallStraightTest) {
	Yanzee yan{};
	std::vector<int> var = { 1,2,3,4,5 };
	std::vector<int> var1 = { 5,4,3,2,1 };
	std::vector<int> var2 = { 5,1,2,4,3 };
	std::vector<int> var3 = { 3,4,2,1,5 };
	std::vector<int> var4 = { 5,3,2,1,1 };
	auto num = Combinations::SmallStraight;
	int yanRes = yan.round(var, num);
	ASSERT_EQ(yanRes, 15);

	yanRes = yan.round(var1, num);
	ASSERT_EQ(yanRes, 15);

	yanRes = yan.round(var2, num);
	ASSERT_EQ(yanRes, 15);

	yanRes = yan.round(var3, num);
	ASSERT_EQ(yanRes, 15);

	yanRes = yan.round(var4, num);
	ASSERT_EQ(yanRes, 0);
}

TEST(TestCaseName, YanzeeYanzTest) {
	Yanzee yan{};
	std::vector<int> var = { 6,6,6,6,6 };
	std::vector<int> var1 = { 5,5,5,5,5 };
	std::vector<int> var2 = { 4,4,4,4,4 };
	std::vector<int> var3 = { 6,6,6,6,1 };
	std::vector<int> var4 = { 5,5,5,5,4 };
	auto num = Combinations::Yanz;
	int yanRes = yan.round(var, num);
	ASSERT_EQ(yanRes, 50);

	yanRes = yan.round(var1, num);
	ASSERT_EQ(yanRes, 50);

	yanRes = yan.round(var2, num);
	ASSERT_EQ(yanRes, 50);

	yanRes = yan.round(var3, num);
	ASSERT_EQ(yanRes, 0);

	yanRes = yan.round(var4, num);
	ASSERT_EQ(yanRes, 0);
}

TEST(TestCaseName, YanzeeFullHouseTest) {
	Yanzee yan{};
	std::vector<int> var = { 6,6,6,6,6 };
	std::vector<int> var1 = { 1,1,5,5,5 };
	std::vector<int> var2 = { 4,4,3,4,3};
	std::vector<int> var3 = { 6,6,6,2,1 };
	std::vector<int> var4 = { 1,5,5,1,5 };
	auto num = Combinations::FullHouse;
	int yanRes = yan.round(var, num);
	ASSERT_EQ(yanRes, 0);

	yanRes = yan.round(var1, num);
	ASSERT_EQ(yanRes, 17);

	yanRes = yan.round(var2, num);
	ASSERT_EQ(yanRes, 18);

	yanRes = yan.round(var3, num);
	ASSERT_EQ(yanRes, 0);

	yanRes = yan.round(var4, num);
	ASSERT_EQ(yanRes, 17);
}