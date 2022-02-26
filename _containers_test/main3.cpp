#include "vector.hpp"
#include <vector>
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream source("testfile", std::ios::binary);
    std::vector<char> data((std::istreambuf_iterator<char>(source)),
                       std::istreambuf_iterator<char>());
    std::cout << data[0] << data[1] << data[2] << std::endl;
    source.close();
    std::ifstream sourceb("testfile", std::ios::binary);
    ft::vector<char> data2((std::istreambuf_iterator<char>(sourceb)),
                       std::istreambuf_iterator<char>());
    std::cout << data2[0] << data2[1] << data2[2] << std::endl;
    return(0);
}