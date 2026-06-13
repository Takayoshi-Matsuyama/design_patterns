#ifndef PROXY_H_
#define PROXY_H_

#include "Subject.h"

class Proxy : public Subject {
    private:
        Subject& realSubject;  // Reference to the real subject that the proxy will control access to
    public:
        Proxy(Subject& subject);
        void Request() override;
};

#endif  // PROXY_H_
