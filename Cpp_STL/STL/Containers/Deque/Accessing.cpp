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
    
    try{
        std::cout << "deq.at(100)" << deq.at(100) << std::endl;
    }
    catch(const std::out_of_range& ex){
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "deq2[2] = " << deq2[2] << '\n';
    

    return 0;  

}