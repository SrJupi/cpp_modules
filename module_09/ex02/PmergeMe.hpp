#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <algorithm>
#include <ctime>

typedef std::pair<int, int>	int_pair;

//Input check
std::vector<int>	checkInput(char *argv[]);
bool				isNumber(std::string str);

//Jacobsthal numbers
int	getNextJacobsthalNumber(unsigned int seq);

//Power of two
int getPowerOfTwo(int num);

//Vector functions
std::vector<int>		mergeInsertSort(std::vector<int> unsortedVec);
std::vector<int_pair>	getPairs(std::vector<int> unsortedVec);
void					orderEachPair(std::vector<int_pair> &pairs);
void					mergeSortPairs(std::vector<int_pair> &pairs);
std::vector<int>		splitPairs(std::vector<int_pair> &pairs, std::vector<int> &unsortedVec, int oddNumber);
int						getAndRemoveAtIndex(std::vector<int> &vec, int index);
void					binaryInsert(std::vector<int> &sortedVec, int numToInsert, int maxIndex);

//Deque functions
std::deque<int>			mergeInsertSort(std::deque<int> unsortedDeq);
std::deque<int_pair>	getPairs(std::deque<int> unsortedVec);
void					orderEachPair(std::deque<int_pair> &pairs);
void					mergeSortPairs(std::deque<int_pair> &pairs);
std::deque<int>			splitPairs(std::deque<int_pair> &pairs, std::deque<int> &unsortedVec, int oddNumber);
int						getAndRemoveAtIndex(std::deque<int> &vec, int index);
void					binaryInsert(std::deque<int> &sortedVec, int numToInsert, int maxIndex);


//
std::ostream & operator<<(std::ostream & os, std::pair<int,int> const & ref);
std::ostream & operator<<(std::ostream & os, std::vector<int> const & ref);
std::ostream & operator<<(std::ostream & os, std::deque<int> const & ref);


void	printPairs(std::vector<int_pair> pairs);


#endif
