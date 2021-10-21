#include <iostream>
#include <exception>

using namespace std;

int main(void) {
    //在可读性和精简性之间做权衡
    range_error r("error");
    //range_error类大概是由exception类继承而来的
    exception* p = &r;

    try {
        //throw r;
        //throw p;
    } catch(range_error err) {
        cout << "Hello!" << endl;
    } catch(exception err) {
        cout << "World!" << endl;
    } catch(exception* err) {
        cout << "Supernova" << endl;
    }

    return 0;
}