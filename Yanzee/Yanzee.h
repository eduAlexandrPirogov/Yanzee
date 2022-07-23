#pragma once
#include <map>
#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>

enum Combinations
{
	Numbers, Pair, TwoPair, ThreeOfKind, FourOfKind, 
	SmallStraight, FullHouse, Yanz, Chance
};

class Yanzee
{

	std::map<Combinations, std::function<int(std::vector<int>)>> combinations;
public:
	Yanzee();
	int round(std::vector<int>& bones, Combinations& comb);
private:
	void init();
	//functions
private:
	std::function<int(std::vector<int>)> isNumbersLambda = [=](std::vector<int> numArrays)
	{
		return std::accumulate(numArrays.begin(), numArrays.end(), 0);
	};

	std::function<int(std::vector<int>)> isPairsLambda = [=](std::vector<int> numArrays)
	{
		std::sort(numArrays.begin(), numArrays.end());
		for (const auto& item : numArrays)
		{
			int count = std::count_if(numArrays.begin(), numArrays.end(), [&item](int a)
				{
					return a == item;
				});
			if (count >= 2)
			{
				return item * 2;
			}

		}
		return 0;
	};

	std::function<int(std::vector<int>)> isTwoPairsLambda = [=](std::vector<int> numArrays)
	{
		std::sort(numArrays.begin(), numArrays.end());
		int result = 0;
		int countOfPairs = 0;
		for (const auto& item : numArrays)
		{
			int count = std::count_if(numArrays.begin(), numArrays.end(), [&item](int a)
				{
					return a == item;
				});

			if (count >= 4)
				return item * 4;
			
			if (count >= 2)
			{
				countOfPairs++;
				result += item * 2;
				numArrays.erase(std::find(numArrays.begin(), numArrays.end(), item));
				numArrays.erase(std::find(numArrays.begin(), numArrays.end(), item));
			}
			if (countOfPairs == 2)
				return result;
		}
		return 0;
	};
};

