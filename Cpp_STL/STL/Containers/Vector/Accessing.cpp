#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> vec{11, 22, 33, 44, 55, 66, 77};

    // 1] first & last element
    cout << "vec.front(): " << vec.front() << '\n';
    cout << "vec.back(): " << vec.back() << '\n';

    // 2] via operator[]
    cout << "vec[3]: " << vec[3] << '\n';

    // 3] at() can throw exception of std::out_of_range
    cout << "vec.at(1): " << vec.at(1) << '\n';

    // Accessing via iterators
    std::vector<int>::const_iterator const_it = vec.cbegin();

    do {

        cout << *const_it << ' ';
        ++const_it;
 
    } while(const_it != vec.cend());
    cout << '\n';
    
    // via raw pointer 
    cout << *(vec.data() + 2) << endl;
    cout.flush();
    
    return 0;

}