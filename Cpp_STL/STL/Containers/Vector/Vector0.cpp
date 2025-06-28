#include <iostream>
#include <vector>
#include <algorithm>


int main()
{

    std::vector<int> vec = {0, 1, 2, 3, 5 ,6 ,7};
    vec[2] = 15;

    std::vector<int> vec1({9, 10, 11, 12, 13, 1, 1});

    std::cout << "size of vector: " << vec.size() << std::endl;
    
    for(auto t : vec){
        std::cout << t << ' ';
    }
    std::cout << std::endl;

    for(auto t : vec1){
        std::cout << t << ' ';
    }
    std::cout << std::endl;

    return 0;

}