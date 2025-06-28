#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto t : v)
        os << t << ' ';
    os << endl; 
    return os;
}

int main() {

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "vector: " << vec;

    // vector<T>::erase(it_pos)
    vec.erase(vec.cbegin());
    cout << "vec after erase: " << vec;

    // vector<T>::erase(it_pos1, it_pos2), range -> [ pos1, pos2 ) 
    vec.erase((vec.begin() + 1), (vec.end() - 3)); // from 3 to 7 (7 not included!)
    cout << vec;

    return 0;
}