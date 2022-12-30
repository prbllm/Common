#include "pch.h"

#include "common_functions.h"

#include <list>

namespace tests
{
	enum class StlContainer
	{
		Vector,
		List,
	};

	class CommonFunctionsFinderTests : public ::testing::TestWithParam<StlContainer>
	{
	public:
		explicit CommonFunctionsFinderTests()
		{
			m_data.reserve(6);

			std::vector<int> first{ m_valueToCheck, 7, 8, -4, m_valueToCheck, m_valueToCheck, m_valueToCheck };
			m_data.emplace_back(std::make_pair(3, std::move(first)));

			std::vector<int> second{ m_valueToCheck, m_valueToCheck, m_valueToCheck, -4, 31, 21, 11 };
			m_data.emplace_back(std::make_pair(3, std::move(second)));

			std::vector<int> third( 5, m_valueToCheck );
			m_data.emplace_back(std::make_pair(5, std::move(third)));

			m_data.emplace_back(std::make_pair(0, std::vector<int>()));

			std::vector<int> fifth{ 0, 0, 0, m_valueToCheck };
			m_data.emplace_back(std::make_pair(1, std::move(fifth)));

			std::vector<int> sixth{ -2, 4, 21, 2 };
			m_data.emplace_back(std::make_pair(0, std::move(sixth)));
		}

	protected:
		void SetValueToCheck(int newValue)
		{
			m_valueToCheck = newValue;
		}

		void CheckMaxConsecutiveFinder() const
		{
			ASSERT_FALSE(m_data.empty()) << "Test data cann't be empty.";

			const auto run = [this](const std::pair<unsigned int, std::vector<int>>& data)
			{
				static const auto param = GetParam();

				if (param == StlContainer::Vector)
				{
					EXPECT_EQ(data.first, common::Finder::findMaxConsecutive(data.second, m_valueToCheck)) << "Error occured with data " << std::endl
						<< common::Printer::generateDebugStringFromContainer(data.second);
				}
				else if (param == StlContainer::List)
				{
					std::list<int> list{ data.second.cbegin(), data.second.cend() };
					EXPECT_EQ(data.first, common::Finder::findMaxConsecutive(list, m_valueToCheck)) << "Error occured with data " << std::endl
						<< common::Printer::generateDebugStringFromContainer(list);
				}
			};

			for (const auto& testData : m_data)
			{
				run(testData);
			}
		}

	private:
		std::vector<std::pair<unsigned int, std::vector<int>>> m_data;
		int m_valueToCheck{ 1 };
	};

	TEST_P(CommonFunctionsFinderTests, MaxConsecutiveTest)
	{
		CheckMaxConsecutiveFinder();
	}

	INSTANTIATE_TEST_CASE_P(CommonTests, CommonFunctionsFinderTests, ::testing::Values(StlContainer::Vector, StlContainer::List));
}