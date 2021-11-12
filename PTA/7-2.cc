#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;

string cleanup_str(const string& str);

int main(void) {
    string Word;
    map<string, int> Map;
    multimap<int, string> Map_reverse;

    while(cin >> Word) {
        if(Word == "!!!!!") {
            break;
        }

        Word = cleanup_str(Word);

        if(Map.find(Word) == Map.cend()) {
            Map[Word] = 1;
        } else {
            ++Map[Word];
        }
    }

    cout << Map.size() << endl;

    for(auto i : Map) {
        // Map_reverse[i.second] = i.first;
        Map_reverse.insert(make_pair(i.second, i.first));
    }

    int count(0);

    for(auto itc = Map_reverse.crbegin(), ite = Map_reverse.crend();
        itc!=ite; ++itc)
    {
        if(count == 10) {
            break;
        }

        cout << itc->second << "=" << itc->first << endl;
        ++count;
    }

    // auto itc = Map.cbegin();
    
    // for(int i = 0; i<10; ++i, ++itc) {
    //     cout << itc->first << "=" << itc->second << endl;
    // }

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