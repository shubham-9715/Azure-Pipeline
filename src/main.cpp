#include <iostream>
#include <string>
#include "calculator.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: calc <add|sub> <a> <b>\n";
        return 1;
    }

    std::string op = argv[1];
    int a = std::stoi(argv[2]);
    int b = std::stoi(argv[3]);

    if (op == "add") {
        std::cout << add(a, b) << std::endl;
    } else if (op == "sub") {
        std::cout << subtract(a, b) << std::endl;
    } else {
        std::cerr << "Invalid operation\n";
        return 1;
    }

    return 0;
}
