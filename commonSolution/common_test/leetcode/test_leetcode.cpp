#include "pch.h"

#include "include/leetcode.h"

namespace tests::leetcode
{
struct MaxScoreWordsData
{
	std::vector<std::string> words{};
	std::vector<char> letters{};
	std::vector<int> score{};
	int result{ 0 };
};

std::ostream& operator<<(std::ostream& os, const MaxScoreWordsData& data)
{
	std::string result{ "Words: [" };
	for (const auto& word : data.words)
	{
		result += word + ",";
	}
	result.erase(result.back());
	result += "]";

	os << result;
	return os;
}

class LeetCodeSolutionFixture : public ::testing::TestWithParam<MaxScoreWordsData>
{
protected:
	[[nodiscard]] int RunSolution() noexcept
	{
		try
		{
			auto temp = GetParam();
			return m_solution.MaxScoreWords(temp.words, temp.letters, temp.score);
		}
		catch (const std::exception& exception)
		{
			ADD_FAILURE() << "Unable to run solution. Exception: " << exception.what();
			return -1;
		}
	}
private:
	::leetcode::Solution m_solution;
};

TEST_P(LeetCodeSolutionFixture, Run)
{
	EXPECT_EQ(GetParam().result, RunSolution());
}

MaxScoreWordsData veryDifficultSample
{
	{ "dbccbcb","bdacbae","eaa","aeccedc","ecaeaa","ebeec","abcb" }
	, { 'a','a','a','a','b','b','b','b','b','b','b','c','c','d','d','d','d','d','d','e','e','e','e' }
	, { 4,10,4,2,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	, 70
};

INSTANTIATE_TEST_CASE_P(CommonTests, LeetCodeSolutionFixture, ::testing::Values(veryDifficultSample));

}
