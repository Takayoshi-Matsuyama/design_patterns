#include <iostream>

#include "Subject.h"
#include "Proxy.h"

using namespace std;

Proxy::Proxy(Subject& subject) : realSubject(subject) {
    // Constructor implementation
    // This could include initializing the proxy with a reference to the real subject
}

void Proxy::Request() {
    // Implementation of the Request method
    // This could include additional logic such as access control, logging, etc.
    cout << "Proxy: Handling Request. Forwarding to RealSubject." << endl;
    this->realSubject.Request();  // Forward the request to the real subject
}
