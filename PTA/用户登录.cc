#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main(void) {
    string name, pwd;
    // int count(0);
    map<string, string> Map{{"admin","123456"}, {"administrator","12345678"},{"root","password"}};

    while(cin >> name >> pwd) {
        if(Map[name] == pwd) {
            cout << "登录成功" << endl;
        } else {
            // ++count;
            cout << "登录失败" << endl;
        }
    }

    return 0;
}