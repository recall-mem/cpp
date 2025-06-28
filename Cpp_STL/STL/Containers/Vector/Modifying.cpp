#include <iostream>
#include <vector>

 
std::ostream& operator<<(std::ostream& os, std::vector<int>& v){
    os << '(' << ' ';
    for(auto t : v)
        os << t << ' ';
    os << ')' << std::endl;
    
    return os;
}

int main()
{
    using std::cout;

    std::vector<int> vec({0, 1, 2, 3, 5 ,6 ,7});
    std::vector<int> vec1(2, 5);
    
    /*
        vector<T>::insert overloads:
        (it_pos, val)
        (it_pos, {list})
        (it_pos, count, val)
        (it_pos, it2_beg, it2_end)
    */  
     
    vec1.insert(vec1.begin(), 2, 10);
    vec1.insert(vec1.cbegin() , {33, 44, 55});
    cout << "vector1: " << vec1;

    std::vector<int> vec2;
    vec2.insert(vec2.begin(), vec.begin(), vec.end());

    // Apped element end of the container
    vec2.push_back(100);
    cout << "vector2: " << vec2;



    struct Obj 
    {
        Obj(int var): var_(var) {};
        Obj() = default;
        int var_;
    };

    // vector<T>::emplace(it_pos, constructor_args...)
    std::vector<Obj> objVec;
    objVec.emplace(objVec.begin(), 12);

    // vector<T>::emplace_back(constructor_args...)
    objVec.emplace_back(100);
    cout << "objVec: ( ";
    cout << objVec.front().var_ << ", ";
    cout << objVec.back().var_ << " )" << std::endl;
    
    return 0;
}