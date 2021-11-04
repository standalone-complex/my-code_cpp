#include <iostream>
#include <sstream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::multimap;

int main(void) {
    int n, sum, num, i = 1, presum;
    string Aline, name;
    multimap<int, std::pair<int, string>> Map;

    cin >> n;

    while(getline(cin, Aline)) {
        sum = 0;
        std::istringstream is(Aline);

        is >> name;

        while(is >> num) {
            sum += num;
        }

        //Map.insert(make_pair(sum, make_pair(i, name)));
    }

    i = 1;

    auto itb = Map.cbegin();
    cout << i << " " << itb->second.first << " " << itb->second.second << " " << itb->first << endl;
    presum = (*itb).first;

    for(auto itc = itb++, ite = Map.cend();
        itc!=ite; ++itc)
    {
        ++i;

        cout << (presum == itc->first ? i-1 : i) << " " << itb->second.first << " " << itb->second.second << itb->first << endl;
    }

    return 0;
}