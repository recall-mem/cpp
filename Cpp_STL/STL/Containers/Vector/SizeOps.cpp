#include <iostream>
#include <vector>


int main() {
    using std::cout;

    std::vector<int> vec;
    
    // currenly allocated storage for vector
    cout << "1. vec.capacity(): " << vec.capacity() << '\n';

    // element currently held in vector
    cout << "1. vec.size(): " << vec.size() << '\n';

    // allocating space for 100 element
    vec.reserve(100);

    cout << "2. vec.capacity(): " << vec.capacity() << '\n';
    cout << "2. vec.size(): " << vec.size() << '\n';
    // freeing unused memory 
    vec.assign(50, 0);
    vec.shrink_to_fit();
    cout << "vec.capacity(): " << vec.capacity() << '\n';

    // vector<T>::resize(count)
    vec.resize(2);
    cout << "vec.size() after resize(2): " << vec.size() << '\n';

    // vector<T>::resize(count, value)
    vec.resize(5, 1);
    cout << "vec.size() after resize(5, 1): " << vec.size() << '\n';
    cout << "vector: ( ";
    
    for(const auto& t : vec)
        cout << t << ' ';
    cout << ')' << std::endl; 

    // return true if container not empty :|
    std::vector<int> empvec;
    empvec.reserve(100);
    cout << "vec.empty(): " << std::boolalpha << vec.empty(); // false
    cout << "\nempvec.empty(): " << empvec.empty() << std::endl; // true
    
    return 0;
}