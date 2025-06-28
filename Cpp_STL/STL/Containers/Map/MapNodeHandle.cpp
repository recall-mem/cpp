#include <map>
#include <iostream>

int main()
{
    std::map<int, char*> icmap{{1, "one"},{2, "two"},{3, "three"}};

    std::map<int, char*>::node_type node = icmap.extract(2);
    
    for(const auto& i : icmap){
        printf("Key: %d, Value: %s\n", i.first, i.second);
    }
    printf("\n");
    
    icmap.insert(std::move(node));

    for(const auto& i : icmap){
        printf("Key: %d, Value: %s\n", i.first, i.second);
    }

    return 0;
}