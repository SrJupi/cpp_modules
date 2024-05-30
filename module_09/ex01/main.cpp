#include "RPN.hpp"

int main(int argc, char *argv[]){
    if (argc != 2) {
        std::cerr << "Wrong number of arguments\nUsage:\n.\\RPN \"math expression in rpn format\"" << std::endl;
        return 1;
    }
    try {
        RPN::doSomeRPN(argv[1]);
    }
    catch (RPN::TooManyNumbersError &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (RPN::NotEnoughNumbersError &e) {
        std::cerr << e.what() << "... You really tried with an empty string?" << std::endl;
    }

    return 0;
}
