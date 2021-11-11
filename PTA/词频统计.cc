#include <iostream>
#include <sstream>
#include <string>
// #include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::map;

string cleanup_str(const string&);

int main(void) {
    int n;
    string Aline;
    string Word;
    map<string, int> Map;

    cin >> n;

    while(cin >> Aline) {
        istringstream is(Aline);

        while(is >> Word) {
            if(Word[0] >= '0' && Word[0] <= '9') {
                continue;
            }

            Word = cleanup_str(Word);

            if(Map.find(Word) == Map.cend()) {
                Map[Word] = 1;
            } else {
                ++Map[Word];
            }
        }
    }

    for(auto& i : Map) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}

inline
string cleanup_str(const string& word)
{
    string ret;

    for(string::const_iterator it = word.cbegin(); it!=word.cend(); ++it)
    {
        //如果不是标点符号
        if(!ispunct(*it))
        {
            //转换小写
            ret += tolower(*it);
        }
    }

    return ret;
}