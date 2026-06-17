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

#include "ConcreteHandler1.h"

#include <iostream>
#include <memory>

ConcreteHandler1::ConcreteHandler1(std::shared_ptr<Handler> successor) : successor(successor) {
    // Constructor to initialize the successor handler
}

void ConcreteHandler1::HandleRequest(const ErrorEvent& event) {
    std::cout << "ConcreteHandler1 handling request." << std::endl;
    if (event.errorLevel == 1) {
        std::cout << "ConcreteHandler1: Handled low level error: " << event.errorMessage << std::endl;
    } else if (successor) {
         successor->HandleRequest(event);
    } else {
        std::cout << "ConcreteHandler1: No handler available for high level error: " << event.errorMessage << std::endl;
    }
}
