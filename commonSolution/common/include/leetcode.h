#pragma once

#include "def.h"

namespace leetcode
{
// for more information https://leetcode.com/problems/maximum-score-words-formed-by-letters/
class Solution final
{
public:
	explicit Solution();

	int MaxScoreWords(std::vector<std::string>& words, const std::vector<char>& letters, std::vector<int>& score);

private:
	int m_maxScore{ 0 };
    std::vector<int> m_freq;

	[[nodiscard]] bool IsValidWord(const std::vector<int>& subsetLetters) const;
	void Check(int w, std::vector<std::string>& words, std::vector<int>& score, std::vector<int>& subsetLetters, int totalScore);
};
}
