#include <iostream>
#include <array>

void printa(int* ptr, size_t size){

    for(int t = 0; t < size; t++){
        std::cout << *(ptr + t) << ' '; 
    }

    std::cout << std::endl;
}

int main(){

    std::array<int, 8> arr{}, dummy;

    dummy.fill(12);
    std::cout << "dummy before swap: ";
    printa(dummy.data(), size_t(8));

    arr.swap(dummy);
    std::cout << "dummy after swap: ";
    printa(dummy.data(), size_t(8));

    std::cout << "arr after swap: ";
    printa(arr.data(), size_t(8));
    
    return 0;
}
