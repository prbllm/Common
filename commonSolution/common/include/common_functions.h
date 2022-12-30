#pragma once

#include "def.h"

#include <iostream>
#include <vector>
#include <string>

namespace common
{
	class Finder final
	{
	public:
		/*!
		* \brief Find max consecuteve of value in container
		* \param[in] data container
		* \param[in] value value
		* \return max consecuteve of value
		*/
		template<class T, class... Rest, template <class, class...> class Container>
		static NO_DISCARD unsigned int findMaxConsecutive(const Container<T, Rest...>& data, T value)
		{
			unsigned int maxResult{ 0 }, tempResult{ 0 };
			for (const auto& num : data)
			{
				if (num == value)
				{
					++tempResult;
				}
				else
				{
					maxResult = std::max(maxResult, tempResult);
					tempResult = 0;
				}
			}
			return std::max(maxResult, tempResult);
		}
	};

	class Printer final
	{
	public:
		/*!
		* \brief Print container
		* \param[in] data container
		*/
		template<class T, class... Rest, template <class, class...> class Container>
		static void printContainer(const Container<T, Rest...>& data, char separator = '\n')
		{
			if (data.empty())
			{
				std::cout << "Container is empty, nothing to print" << std::endl;
				return;
			}

			std::cout << "Container size is " << data.size() << std::endl;
			for (const auto& value : data)
			{
				std::cout << value << separator;
			}
			std::cout << std::endl;
		}

		template<class T, class... Rest, template <class, class...> class Container>
		static std::string generateDebugStringFromContainer(const Container<T, Rest...>& data, char separator = '\n')
		{
			std::string res{ "Container size is " + std::to_string(data.size()) + "\n" };
			if (data.empty())
			{
				res += "( empty )";
				return res;
			}
			
			for (const auto& value : data)
			{
				res += std::to_string(value) + separator;
			}
			return res;
		}
	};

} // common