#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

typedef std::pair<int, int>	int_pair;

//Input check
std::vector<int> checkInput(std::string intStr);

//Jacobsthal numbers
int	getNextJacobsthalNumber(unsigned int seq);

//Vector functions
std::vector<int>        mergeInsertSort(std::vector<int> unsortedVec);
std::vector<int_pair>   getPairs(std::vector<int> unsortedVec);
void					orderEachPair(std::vector<int_pair> &pairs);
void					mergeSortPairs(std::vector<int_pair> &pairs);
std::vector<int>		splitPairs(std::vector<int_pair> &pairs, std::vector<int> &unsortedVec, int oddNumber);

//Deque functions
std::deque<int>	mergeInsertSort(std::deque<int> unsortedDeq);


//
std::ostream & operator<<(std::ostream & os, std::pair<int,int> const & ref);
std::ostream & operator<<(std::ostream & os, std::vector<int> const & ref);

void	printPairs(std::vector<int_pair> pairs);


#endif
