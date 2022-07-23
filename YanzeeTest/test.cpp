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