#include <set>
#include <iostream>

using namespace std;


struct Data
{
    int val;
    
    Data(){
        val = rand()%10;
    }
    Data(int Val) : val(Val)
    {}

};

int main()
{
    auto comp = [](const Data& d1, const Data& d2){return d1.val < d2.val;};
    
    std::set<Data, decltype(comp)> DataSet(comp);
    
    DataSet.emplace(5);
    DataSet.emplace(15);
    DataSet.emplace(-5);
    DataSet.emplace(0);
    
    for(auto& i : DataSet){
        cout << &i << " -> " << i.val << '\n';
    }
    cout << endl;

    auto it = DataSet.cbegin();

    std::advance(it, 2);

    cout << it->val << endl;

    return 0;
}