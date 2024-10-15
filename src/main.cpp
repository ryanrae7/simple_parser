#include <iostream>
#include <stdio.h>
#include <sstream>
#include "rules.cpp"

int main()
{
    std::string input = "Hello world 101 != 50";
    parse(input);
    return 0; 
}