#include <iostream>
#include <string>
#include <vector>

//using 指示
//using namespace std;

int main(void) {
    int T;
    std::string Aline;
    std::vector<std::string> Lines;
    

    std::cin >> T;
    getline(std::cin, Aline);

    while(getline(std::cin, Aline)) {
        //std::cout << "cout: " << Aline << ";" << std::endl;
        Lines.push_back(Aline);
    }

    for(auto i : Lines) {
        std::cout << "cout: " << i << std::endl;
    }

    return 0;
}