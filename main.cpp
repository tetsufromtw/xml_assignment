#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "xml_validator.hpp"

int main(int argc, char *argv[]) {
    XMLValidator xmlValidator;
    std::string line;

    if (argc > 1) {
        std::ifstream file(argv[1]);
        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::cout << line << ": " 
                          << std::boolalpha << xmlValidator.DeterminXml(line) << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Unable to open file" << std::endl;
            return 1;
        }
    } else {
        std::cout << "Input: ";
        while (std::getline(std::cin, line)) {
            std::cout << std::endl;
            std::cout  << "Output: " 
                      << std::boolalpha << xmlValidator.DeterminXml(line) << std::endl;
            std::cout << "Input: ";
        }
    }
    return 0;
}
