#include <iostream>
#include <pqxx/util>
#include <pqxx/version>

int main() {
    std::cout << "libpqxx version: " 
              << PQXX_VERSION << "."
              << PQXX_VERSION_MAJOR << "."
              << PQXX_VERSION_MINOR << std::endl;
    return 0;
}
