#include "PmergeMe.hpp"

int main(int argc, char *argv[]){
    if (argc < 2) {
        std::cerr << "Wrong number of arguments\nUsage:\n.\\PmergeMe num [num...]" << std::endl;
        return 1;
    }
    argv++;
    try {
        std::vector<int> unsortedVec = checkInput(argv);
        std::cout << "Before: " << unsortedVec << std::endl;
        const std::clock_t vec_start = std::clock();
        std::vector<int> sortedVec = mergeInsertSort(unsortedVec);
        const std::clock_t vec_end = std::clock();
        std::cout << "After: " << sortedVec << std::endl;
        std::cout << "Time to process a range of "
            << sortedVec.size()
            << " elements with std::vector = "
            << 1000.0 * (vec_end - vec_start) / CLOCKS_PER_SEC
            << "ms" << std::endl << std::endl;
        
        std::deque<int> unsortedDeq (unsortedVec.begin(), unsortedVec.end());
        const std::clock_t deq_start = std::clock();
        std::deque<int> sortedDeq = mergeInsertSort(unsortedDeq);
        const std::clock_t deq_end = std::clock();
        std::cout << "Time to process a range of "
            << sortedDeq.size()
            << " elements with std::deque = "
            << 1000.0 * (deq_end - deq_start) / CLOCKS_PER_SEC 
            << "ms" << std::endl;
    }
    catch (const char* e) {
        std::cerr << "Error: Non-numeric or negative input detected: " << e << std::endl;
    }

    return 0;
}
