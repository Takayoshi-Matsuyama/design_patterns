#include <iostream>

#include "Subject.h"
#include "RealSubject.h"
#include "Proxy.h"

using namespace std;

int main() {
    cout << "GoF Proxy Pattern Example" << endl;

    RealSubject realSubject;
    Proxy proxy(realSubject);
    proxy.Request();

    return 0;
}
