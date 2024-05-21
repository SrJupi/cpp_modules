#include "Serializer.hpp"

int main (void) {
    Data a;

    a.id = 42;
    a.name = "Lucas";

    std::cout << "Old data: " << &a << std::endl;

    uintptr_t uptr = Serializer::serialize(&a);
    std::cout << "Uint pointer: " << uptr << std::endl;

    Data *b = Serializer::deserialize(uptr);

    std::cout <<  "New data: " << b << std::endl;
    std::cout << b->id << " - " << b->name << std::endl;
 
    return (0);
}