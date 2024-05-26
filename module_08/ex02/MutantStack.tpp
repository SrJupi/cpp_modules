#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>::stack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& ref): std::stack<T>::stack(ref)
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& ref)
{
    if (*this != ref) {
        this->c = ref->c;
    }
    return (*this);
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
inline typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
inline typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}
