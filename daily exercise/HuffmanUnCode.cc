#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include "/home/tyf/Downloads/json.hpp"

using std::cin;
using std::cout;
using std::ifstream;
using std::endl;
using std::istringstream;
using std::string;
using std::map;
using std::vector;
using nlohmann::json;

int main(void) {
    // 哈夫曼解码，需要一张编码表
    map<string, string> CodeTable;
    ifstream file("/home/tyf/Code/my-code_cpp/daily exercise/HuffmanTable.json");
    json js;
    string Aline, Code;
    char c;

    js.parse(file);

    for(auto item : js.items()) {
        CodeTable[item.key()] = item.value();
    }

    cin >> Aline;
    istringstream is(Aline);
    
    // 解码
    while(is >> c) {
        Code += c;

        if(CodeTable.find(Code) != CodeTable.cend()) {
            cout << CodeTable[Code];
            Code = "";
        }
    }

    return 0;
}