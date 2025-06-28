#include <iostream>
#include <vector>
#include <ostream>
 
std::ostream& operator<<(std::ostream& os, std::vector<int>& v){
    for(auto t : v)
        os << t << ' ';
    os << std::endl;
    
    return os;
}

int main()
{
    using std::cout;

    std::vector<int> vec;

    // assign(count, value)
    vec.assign(12, 5);
    cout << vec;

    // assign c-style array
    int carr[] = {1,2,3,4,5,6,7,8,9,-1};
    vec.assign(carr, carr + sizeof(carr) / 4 /*size of int*/);
    cout << vec;

    // assign({list})
    std::vector<const char*> words;
    words.assign({"first line\n", "second line\n"});
    cout << words[0];
    cout << words[1];
    cout.flush();

    

    return 0;
}