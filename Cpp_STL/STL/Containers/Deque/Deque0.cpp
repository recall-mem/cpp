#include <iostream>
#include <deque>


std::ostream& operator<<(std::ostream& os, std::deque<int>& c){
    for(auto t : c)
        os << t << ' ';
    os << std::endl;
    
    return os;
}


int main()
{
    std::deque<int> deq({1,3,5,7,9,11});
    std::deque<int> deq2 = {2,4,6,8,10};

    std::cout << "deq = " << deq;
    std::cout << "deq.size(): " << deq.size() << '\n'; // 6

    return 0;
}