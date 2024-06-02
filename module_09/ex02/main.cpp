#include "PmergeMe.hpp"

int main(int argc, char *argv[]){
    if (argc < 2) {
        std::cerr << "Wrong number of arguments\nUsage:\n.\\RPN \"math expression in rpn format\"" << std::endl;
        return 1;
    }
    std::vector<int> unsortedVec = checkInput(argv[1]);
    std::deque<int> unsortedDeq (unsortedVec.begin(), unsortedVec.end());
    std::vector<int> sortedVec = mergeInsertSort(unsortedVec);
/*     (void)argv;
    for (int i = 0; i < 15; i++) {
        std::cout << i << " -> " << getNextJacobsthalNumber(i) << std::endl;
    } */

    return 0;
}
