#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int FindMax(const vector<int>&);
void RadixSort(vector<int>&);

int main(void) {
    vector<int> Array{19, 28, 37, 46, 55, 64, 73, 82, 91, 100};

    RadixSort(Array);

    for(auto i : Array) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

int FindMax(const vector<int>& Array) {
    int ret = 1, p = 10;

    for(auto i : Array) {
        if(i > p) {
            p *= 10;
            ++ret;
        }
    }

    return ret;
}

void RadixSort(vector<int>& Array) {
    int LoopTimes = FindMax(Array);
    vector<vector<int>> Bucket(10, vector<int>());

    for(int i = 0; i <= LoopTimes; ++i) {
        for(auto j : Array) {
            Bucket[(j/static_cast<int>(pow(10, i)))%10].push_back(j);
        }

        Array = vector<int>();

        for(auto i : Bucket) {
            for(auto j : i) {
                Array.push_back(j);
            }
        }

        Bucket = vector<vector<int>>(10, vector<int>());
    }

    return;
}