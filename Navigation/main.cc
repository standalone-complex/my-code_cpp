#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include "Navigation.hh"
#include "Functions.hh"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

int main(void) {
    VNode G;
    ALGraph G1;

    LoadFile(G);
    Create(G1);

    while(1) {
        Menu_1();
    }

    return 0;
}