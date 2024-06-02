#include "PmergeMe.hpp"

std::vector<int> checkInput(std::string intStr)
{
	std::vector<int> unsortedVec;
	std::istringstream iss(intStr);
	std::string num;
	while (std::getline(iss, num, ' '))
	{
		unsortedVec.push_back(std::atoi(num.c_str()));
	}
	return (unsortedVec);
}

int getNextJacobsthalNumber(unsigned int seq)
{
    if (seq == 0)
		return 0;
	if (seq == 1)
		return 1;
	return 2 * getNextJacobsthalNumber(seq - 2) + getNextJacobsthalNumber(seq - 1);
}

std::vector<int> mergeInsertSort(std::vector<int> unsortedVec)
{
	int	oddNumber;

	// 1. Group the elements of X into n / 2 pairs of elements, arbitrarily,
	//	leaving one element unpaired if there is an odd number of elements.
	std::vector<int_pair> pairs = getPairs(unsortedVec);
	oddNumber = pairs.size() * 2 == unsortedVec.size() ?
		-1 : unsortedVec[unsortedVec.size() / 2];
	// 2. Perform n / 2  comparisons, one per pair,
	//	to determine the larger of the two elements in each pair.
	//printPairs(pairs);
	orderEachPair(pairs);
	std::cout << "PRE ORDER:\n";
	printPairs(pairs);
	// 3. Recursively sort the n / 2 larger elements from each pair,
	//	creating a sorted sequence S of n / 2 of the input elements,
	//	in ascending order.
	mergeSortPairs(pairs);
	std::cout << "POS ORDER:\n";
	printPairs(pairs);
	std::cout << "Before:\n" << unsortedVec << std::endl;
	std::vector<int> sortedVec = splitPairs(pairs, unsortedVec, oddNumber);
	std::cout << "Unsorted:\n" << unsortedVec << std::endl;
	std::cout << "Sorted:\n" << sortedVec << std::endl;

	// 4. Insert at the start of S  the element that was paired with the first and smallest element of S .
	sortedVec.insert(sortedVec.begin(), unsortedVec[0]);
	std::cout << "Unsorted:\n" << unsortedVec << std::endl;
	std::cout << "Sorted:\n" << sortedVec << std::endl;
	// 5. Insert the remaining n / 2  − 1 elements of X ∖ S into S,
	//	one at a time,
	//	with a specially chosen insertion ordering described below. Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.
	

	return sortedVec;
}

std::vector<int_pair> getPairs(std::vector<int> unsortedVec)
{
	std::vector<int_pair> pairs;
	for (size_t i = 0, j = unsortedVec.size() - 1; i < j; i++, j--)
	{
		pairs.push_back(std::make_pair<int, int>(unsortedVec[i],
				unsortedVec[j]));
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
	if (pairs.size() <= 1)
		return ;
	size_t mid = pairs.size() / 2;
	std::vector<int_pair> left (pairs.begin(), pairs.begin() + mid);
	std::vector<int_pair> right (pairs.begin() + mid, pairs.end());
	mergeSortPairs(left);
	mergeSortPairs(right);
	pairs.clear();
	while (!left.empty() && !right.empty()) {
		if (left.front().second < right.front().second) {
			pairs.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			pairs.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty()) {
		pairs.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		pairs.push_back(right.front());
		right.erase(right.begin());
	}
	
}

std::vector<int> splitPairs(std::vector<int_pair> &pairs, std::vector<int> &unsortedVec, int oddNumber)
{
    std::vector<int> sortedVec;
	unsortedVec.clear();
	for (size_t i = 0; i < pairs.size(); i++) {
		unsortedVec.push_back(pairs[i].first);
		sortedVec.push_back(pairs[i].second);
	}
	if (oddNumber >= 0) {
		unsortedVec.push_back(oddNumber);
	}
	return sortedVec;
}

std::ostream &operator<<(std::ostream &os, std::vector<int> const &ref)
{
	os << "Vector: ";
	for (size_t i = 0; i < ref.size(); i++) {
		os << ref[i] << " ";
	}
	return (os);}

void printPairs(std::vector<int_pair> pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i] << std::endl;
}

std::ostream &operator<<(std::ostream &os, int_pair const &ref)
{
	os << "Pair: " << ref.first << " - " << ref.second;
	return (os);
}
