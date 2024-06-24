#include "leetcode.h"

namespace leetcode
{

Solution::Solution()
{
    m_freq = std::vector<int>(26, 0);
}

int Solution::MaxScoreWords(std::vector<std::string>& words, const std::vector<char>& letters, std::vector<int>& score)
{
	const auto w = static_cast<int>(words.size());
	auto subsetLetters = std::vector<int>(m_freq.size(), 0);

    for (const char c : letters)
    {
        m_freq[c - 'a']++;
    }
    Check(w - 1, words, score, subsetLetters, 0);
    return m_maxScore;
}

bool Solution::IsValidWord(const std::vector<int>& subsetLetters) const
{
    for (int c = 0; c < 26; c++) {
        if (m_freq[c] < subsetLetters[c])
        {
            return false;
        }
    }
    return true;
}

void Solution::Check(int w, std::vector<std::string>& words, std::vector<int>& score, std::vector<int>& subsetLetters, int totalScore)
{
    if (w == -1)
    {
        m_maxScore = std::max(m_maxScore, totalScore);
        return;
    }

    Check(w - 1, words, score, subsetLetters, totalScore);

    const auto length = static_cast<int>(words[w].length());

    for (int i = 0; i < length; i++) {
	    const int c = words[w][i] - 'a';
        subsetLetters[c]++;
        totalScore += score[c];
    }

    if (IsValidWord(subsetLetters))
    {
        Check(w - 1, words, score, subsetLetters, totalScore);
    }

    for (int i = 0; i < length; i++)
    {
	    const int c = words[w][i] - 'a';
        subsetLetters[c]--;
        totalScore -= score[c];
    }
}

}
