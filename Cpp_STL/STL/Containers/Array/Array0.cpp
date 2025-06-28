#include <iostream>
#include <array>


int main(){

    std::array<int, 10> arr({0,1,2,3,4,5,6});
    arr[9] = 10;

    std::array<char, 12> charray{"hello world"};

    for(const auto& t : arr)
       std::cout << t << ' ';
    
    std::cout.flush();

    return 0;
}
