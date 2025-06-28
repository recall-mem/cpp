#include <iostream>
#include <iterator>
#include <array>


int main()
{

    using std::cout;

    std::array<int, 8> arr({0,1,2,3,4,5,6,7});

    // 1] first & last element
    cout << "arr.front(): " << arr.front() << '\n';
    cout << "arr.back(): " << arr.back() << '\n';

    // 2] run time access
    cout << "arr[3]: " << arr[3] << '\n';

    // 3] at() can throw exception of std::out_of_range
    cout << "arr.at(1): " << arr.at(1) << '\n';

    // 4] unline at() and operator[], std::get enforced at compile time
    cout << "std::get<5>(arr): " << std::get<5>(arr) << '\n';

    // Accessing via iterators
    std::array<int, 8>::const_iterator const_it = arr.cbegin();

    do {

        cout << *const_it << ' ';
        ++const_it;
 
    } while(const_it != arr.cend());
    cout.flush();

    return 0;

}