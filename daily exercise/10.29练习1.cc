#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int main(void) {
    int T;
    int m, n, item;
    bool flag(true);

    cin >> T;

    for(int i = 0; i<T; ++i) {
        cin >> m >> n;

        int array[m][n] = {0};

        for(int i1 = 0; i1<m; ++i1) {
            for(int i2 = 0; i2<n; ++i2) {
                cin >> array[i1][i2];
            }
        }

        for(int i1 = 0; i1<m; ++i1) {
            std::find(array+i1, array+i1+1, std::min(array+i1, array+i1+1));
        }
    return 0;
}