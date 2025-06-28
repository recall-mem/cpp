#include <iostream>
#include <array>

int main()
{   
    using std::cout;

    std::array<char, 15> arr{"Hello World\n"};
    
    cout << &arr[0];

    cout << "arr.size(): " << arr.size() << '\n';

    cout << "arr.max_size(): " << arr.max_size() << '\n';

    cout << std::boolalpha << "arr.empty(): " << arr.empty() << '\n';
    
    cout << "Default: is \\0? " << (arr[14]=='\0') << std::endl;
    
    return 0;
}