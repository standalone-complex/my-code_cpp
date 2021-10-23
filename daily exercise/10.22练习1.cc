#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>

int main(void) {
    int T, n, i, j;
    std::string Aline;
    std::vector<int> Array;
    std::vector<std::tuple<int, int, std::vector<int>>> Tuples;

    std::cin >> T;
    getline(std::cin, Aline);

    // std::cout << "Hello" << std::endl;

    while(getline(std::cin, Aline)) {
        std::cout << "Hey!" << std::endl;
        std::istringstream is(Aline);

        is >> n >> i >> j;

        // std::cout << "Hey!" << std::endl;
        
        Tuples.push_back(std::tuple<int, int, std::vector<int>>(i, j, std::vector<int>()));

        auto ref = std::get<2>(Tuples[Tuples.size() - 1]);
        while(is >> T) { 
            ref.push_back(T);
            // std::cout << "World" << std::endl;
        }
    }

    for(auto it1 : Tuples) {
        // std::cout << "Supernova" << std::endl;
        i = std::get<0>(it1) - 1;
        j = std::get<1>(it1) - 1;
        Array = std::get<2>(it1);

        for(int it2=0, ite = Array.size();
            it2<ite; ++it2) {
                // std::cout << "Carry" << std::endl;
            if(it2>=i && it2<=j) {
                std::cout << Array[j--] << " " << std::flush;
                i++;
            } else {
                std::cout << Array[it2] << " " << std::flush;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}