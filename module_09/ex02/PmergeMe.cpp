#include "PmergeMe.hpp"

std::vector<int> checkInput(char *argv[])
{

	std::vector<int> unsortedVec;
	while (*argv)
	{
		if (!isNumber(*argv))
			throw	*argv;
		unsortedVec.push_back(std::atoi(*argv));
		argv++;
	}
	return (unsortedVec);
}

bool	isNumber(std::string str)
{
	if (str.empty())
		return (false);
	std::string::iterator it = str.begin();
	if (*it == '+' && str.size() > 1)
		it++;
	for (; it != str.end(); it++)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

int	getNextJacobsthalNumber(unsigned int seq)
{
	if (seq == 0)
		return (0);
	if (seq == 1)
		return (1);
	return (2 * getNextJacobsthalNumber(seq - 2) + getNextJacobsthalNumber(seq
			- 1));
}

int	getPowerOfTwo(int num)
{
	int	nextPow;

	nextPow = std::pow(2, num);
	if (num > 1)
	{
		nextPow = nextPow - getPowerOfTwo(num - 1);
	}
	return (nextPow);
}

std::vector<int> mergeInsertSort(std::vector<int> unsortedVec)
{
	int	oddNumber;
	int	i;
	int	alreadyInserted;
	int	powerOfTwo;
	int	maxIndex;

	oddNumber = -1;
	// 1. Group the elements of X into n / 2 pairs of elements, arbitrarily,
	//	leaving one element unpaired if there is an odd number of elements.
	if (unsortedVec.size() % 2 != 0)
	{
		oddNumber = unsortedVec[unsortedVec.size() - 1];
		unsortedVec.pop_back();
	}
	std::vector<int_pair> pairs = getPairs(unsortedVec);
	// 2. Perform n / 2  comparisons, one per pair,
	//	to determine the larger of the two elements in each pair.
	// printPairs(pairs);
	orderEachPair(pairs);
	// 3. Recursively sort the n / 2 larger elements from each pair,
	//	creating a sorted sequence S of n / 2 of the input elements,
	//	in ascending order.
	mergeSortPairs(pairs);
	std::vector<int> sortedVec = splitPairs(pairs, unsortedVec, oddNumber);
	// 4. Insert at the start of S  the element that was paired with the first and smallest element of S .
	sortedVec.insert(sortedVec.begin(), getAndRemoveAtIndex(unsortedVec, 0));
	// 5. Insert the remaining n / 2  − 1 elements of X ∖ S into S,
	//	one at a time,
	//	with a specially chosen insertion ordering described below.
	// Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.
	i = 1;
	alreadyInserted = 0;
	while (unsortedVec.size())
	{
		powerOfTwo = getPowerOfTwo(i);
		while (powerOfTwo > static_cast<int>(unsortedVec.size()))
		{
			powerOfTwo--;
		}
		maxIndex = getNextJacobsthalNumber(i + 1) + powerOfTwo + alreadyInserted
			- 1;
		while (powerOfTwo > 0)
		{
			binaryInsert(sortedVec, getAndRemoveAtIndex(unsortedVec, powerOfTwo
					- 1), maxIndex);
			powerOfTwo--;
			alreadyInserted++;
		}
		i++;
	}
	return (sortedVec);
}

std::vector<int_pair> getPairs(std::vector<int> unsortedVec)
{
	std::vector<int_pair> pairs;
	for (size_t i = 1; i < unsortedVec.size(); i += 2)
	{
		pairs.push_back(std::make_pair<int, int>(unsortedVec[i - 1],
				unsortedVec[i]));
	}
	return (pairs);
}

void	orderEachPair(std::vector<int_pair> &pairs)
{
	for (std::vector<int_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first > (*it).second)
		{
			std::swap((*it).first, (*it).second);
		}
	}
}

void	mergeSortPairs(std::vector<int_pair> &pairs)
{
	size_t	mid;

	if (pairs.size() <= 1)
		return ;
	mid = pairs.size() / 2;
	std::vector<int_pair> left(pairs.begin(), pairs.begin() + mid);
	std::vector<int_pair> right(pairs.begin() + mid, pairs.end());
	mergeSortPairs(left);
	mergeSortPairs(right);
	pairs.clear();
	while (!left.empty() && !right.empty())
	{
		if (left.front().second < right.front().second)
		{
			pairs.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			pairs.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty())
	{
		pairs.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		pairs.push_back(right.front());
		right.erase(right.begin());
	}
}

std::vector<int> splitPairs(std::vector<int_pair> &pairs,
	std::vector<int> &unsortedVec, int oddNumber)
{
	std::vector<int> sortedVec;
	unsortedVec.clear();
	for (size_t i = 0; i < pairs.size(); i++)
	{
		unsortedVec.push_back(pairs[i].first);
		sortedVec.push_back(pairs[i].second);
	}
	if (oddNumber >= 0)
	{
		unsortedVec.push_back(oddNumber);
	}
	return (sortedVec);
}

int	getAndRemoveAtIndex(std::vector<int> &vec, int index)
{
	int	tmp;

	tmp = vec[index];
	vec.erase(vec.begin() + index);
	return (tmp);
}

void	binaryInsert(std::vector<int> &sortedVec, int numToInsert, int maxIndex)
{
	int	minIndex;
	int	middle;

	minIndex = 0;
	while (minIndex <= maxIndex)
	{
		middle = minIndex + ((maxIndex - minIndex) / 2);
		if (sortedVec[middle] < numToInsert)
		{
			minIndex = middle + 1;
		}
		else if (sortedVec[middle] > numToInsert)
		{
			maxIndex = middle - 1;
		}
		else
		{
			sortedVec.insert(sortedVec.begin() + middle, numToInsert);
			return ;
		}
	}
	if (minIndex >= static_cast<int>(sortedVec.size()))
	{
		sortedVec.push_back(numToInsert);
	}
	else
	{
		sortedVec.insert(sortedVec.begin() + minIndex, numToInsert);
	}
}

std::deque<int> mergeInsertSort(std::deque<int> unsortedDeque)
{
	int	oddNumber;
	int	i;
	int	alreadyInserted;
	int	powerOfTwo;
	int	maxIndex;

	oddNumber = -1;
	// 1. Group the elements of X into n / 2 pairs of elements, arbitrarily,
	//	leaving one element unpaired if there is an odd number of elements.
	if (unsortedDeque.size() % 2 != 0)
	{
		oddNumber = unsortedDeque[unsortedDeque.size() - 1];
		unsortedDeque.pop_back();
	}
	std::deque<int_pair> pairs = getPairs(unsortedDeque);
	// 2. Perform n / 2  comparisons, one per pair,
	//	to determine the larger of the two elements in each pair.
	// printPairs(pairs);
	orderEachPair(pairs);
	// 3. Recursively sort the n / 2 larger elements from each pair,
	//	creating a sorted sequence S of n / 2 of the input elements,
	//	in ascending order.
	mergeSortPairs(pairs);
	std::deque<int> sortedDeque = splitPairs(pairs, unsortedDeque, oddNumber);
	// 4. Insert at the start of S  the element that was paired with the first and smallest element of S .
	sortedDeque.insert(sortedDeque.begin(), getAndRemoveAtIndex(unsortedDeque,
			0));
	// 5. Insert the remaining n / 2  − 1 elements of X ∖ S into S,
	//	one at a time,
	//	with a specially chosen insertion ordering described below.
	// Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.
	i = 1;
	alreadyInserted = 0;
	while (unsortedDeque.size())
	{
		powerOfTwo = getPowerOfTwo(i);
		while (powerOfTwo > static_cast<int>(unsortedDeque.size()))
		{
			powerOfTwo--;
		}
		maxIndex = getNextJacobsthalNumber(i + 1) + powerOfTwo + alreadyInserted
			- 1;
		while (powerOfTwo > 0)
		{
			binaryInsert(sortedDeque, getAndRemoveAtIndex(unsortedDeque,
					powerOfTwo - 1), maxIndex);
			powerOfTwo--;
			alreadyInserted++;
		}
		i++;
	}
	return (sortedDeque);
}

std::deque<int_pair> getPairs(std::deque<int> unsortedDeque)
{
	std::deque<int_pair> pairs;
	for (size_t i = 1; i < unsortedDeque.size(); i += 2)
	{
		pairs.push_back(std::make_pair<int, int>(unsortedDeque[i - 1],
				unsortedDeque[i]));
	}
	return (pairs);
}

void	orderEachPair(std::deque<int_pair> &pairs)
{
	for (std::deque<int_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first > (*it).second)
		{
			std::swap((*it).first, (*it).second);
		}
	}
}

void	mergeSortPairs(std::deque<int_pair> &pairs)
{
	size_t	mid;

	if (pairs.size() <= 1)
		return ;
	mid = pairs.size() / 2;
	std::deque<int_pair> left(pairs.begin(), pairs.begin() + mid);
	std::deque<int_pair> right(pairs.begin() + mid, pairs.end());
	mergeSortPairs(left);
	mergeSortPairs(right);
	pairs.clear();
	while (!left.empty() && !right.empty())
	{
		if (left.front().second < right.front().second)
		{
			pairs.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			pairs.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty())
	{
		pairs.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		pairs.push_back(right.front());
		right.erase(right.begin());
	}
}

std::deque<int> splitPairs(std::deque<int_pair> &pairs,
	std::deque<int> &unsortedDeque, int oddNumber)
{
	std::deque<int> sortedDeque;
	unsortedDeque.clear();
	for (size_t i = 0; i < pairs.size(); i++)
	{
		unsortedDeque.push_back(pairs[i].first);
		sortedDeque.push_back(pairs[i].second);
	}
	if (oddNumber >= 0)
	{
		unsortedDeque.push_back(oddNumber);
	}
	return (sortedDeque);
}

int	getAndRemoveAtIndex(std::deque<int> &deq, int index)
{
	int	tmp;

	tmp = deq[index];
	deq.erase(deq.begin() + index);
	return (tmp);
}

void	binaryInsert(std::deque<int> &sortedDeque, int numToInsert,
		int maxIndex)
{
	int	minIndex;
	int	middle;

	minIndex = 0;
	while (minIndex <= maxIndex)
	{
		middle = minIndex + ((maxIndex - minIndex) / 2);
		if (sortedDeque[middle] < numToInsert)
		{
			minIndex = middle + 1;
		}
		else if (sortedDeque[middle] > numToInsert)
		{
			maxIndex = middle - 1;
		}
		else
		{
			sortedDeque.insert(sortedDeque.begin() + middle, numToInsert);
			return ;
		}
	}
	if (minIndex >= static_cast<int>(sortedDeque.size()))
	{
		sortedDeque.push_back(numToInsert);
	}
	else
	{
		sortedDeque.insert(sortedDeque.begin() + minIndex, numToInsert);
	}
}

std::ostream &operator<<(std::ostream &os, std::vector<int> const &ref)
{
	for (size_t i = 0; i < ref.size(); i++)
	{
		os << ref[i] << " ";
	}
	return (os);
}

std::ostream &operator<<(std::ostream &os, std::deque<int> const &ref)
{
	for (size_t i = 0; i < ref.size(); i++)
	{
		os << ref[i] << " ";
	}
	return (os);
}

void	printPairs(std::vector<int_pair> pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i] << std::endl;
}

std::ostream &operator<<(std::ostream &os, int_pair const &ref)
{
	os << "Pair: " << ref.first << " - " << ref.second;
	return (os);
}
