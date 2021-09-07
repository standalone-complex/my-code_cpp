#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

//我超，匚艹的内存管理是怎么整的
void words_transform(ifstream&, ifstream&);
map<string, string> buildmap(ifstream&);
const string& transform(const string&, const map<string, string>&);

int main(void)
{
    ifstream inputfile("9.6.2_inputfile.txt");
    ifstream mapfile("9.6.2_mapfile.txt");

    words_transform(inputfile, mapfile);

    return 0;
}

void words_transform(ifstream& inputfile, ifstream& mapfile)
{
    auto trans_map = buildmap(mapfile);
    string words;
    string word;
    bool firstword(true);

    //为啥要用getline？为了换行吗
    while(getline(inputfile, words))
    {
        istringstream is(words);
        firstword = true;

        while(is >> word)
        {
            if(firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";
            }

            cout << transform(word, trans_map);
        }

        cout << endl;
    }

    return;
}

map<string, string> buildmap(ifstream& mapfile)
{
    string words;
    string key;
    string value;
    map<string, string> trans_map;

    while(getline(mapfile, words))
    {
        istringstream is(words);

        is >> key >> value;

        trans_map[key] = value;
    }

    return trans_map;
}

const string& transform(const string& word, const map<string, string>& trans_map)
{
    auto _1 = trans_map.find(word);

    //如果没有
    if(_1 == trans_map.cend())
    {
        return word;
    }
    
    return _1->second;
}