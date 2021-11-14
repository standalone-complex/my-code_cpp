#include <string>
#include <map>

using std::map;
using std::string;

class MapSum {
public:
    MapSum() = default;
    
    void insert(string key, int val) {
        Map[key] = val;
    }
    
    int sum(string prefix) {
        int ret(0);

        string s;

        for(auto it : Map) {
            s = it.first;

            if(s.find(prefix) == 0) {
                ret += it.second;
            }
        }

        return ret;
    }
private:
    map<string, int> Map;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */