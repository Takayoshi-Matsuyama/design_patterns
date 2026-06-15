// Copyright 2026 Takayoshi Matsuyama
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <memory>

#include "Proxy.h"
#include "RealSubject.h"

using namespace std;

void Proxy::Request() {
    // Implementation of the Request method
    // This could include additional logic such as access control, logging, etc.
    cout << "Proxy: Handling Request. Forwarding to RealSubject." << endl;

    if (!realSubject) {
        // Lazy initialization of the real subject
        realSubject = make_unique<RealSubject>();
    }
    this->realSubject->Request();  // Forward the request to the real subject
}
