#include "Yanzee.h"

Yanzee::Yanzee()
{
	init();
}

void Yanzee::init()
{
	combinations[Numbers] = isNumbersLambda;
	combinations[Pair] = isPairsLambda;
	combinations[TwoPair] = isTwoPairsLambda;
	combinations[ThreeOfKind] = isThreeOfKindLambda;
};

int Yanzee::round(std::vector<int>& bones, Combinations& comb)
{
	return combinations[comb](bones);
};
