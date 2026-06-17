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

#include "ConcreteHandler2.h"

#include <iostream>
#include <memory>

ConcreteHandler2::ConcreteHandler2(std::shared_ptr<Handler> successor) : successor(std::move(successor)) {
    // Constructor to initialize the successor handler
}

void ConcreteHandler2::HandleRequest(const ErrorEvent& event) {
    std::cout << "ConcreteHandler2 handling request." << std::endl;
    if (event.errorLevel == 2) {
        std::cout << "ConcreteHandler2: Handled high level error: " << event.errorMessage << std::endl;
    } else if (successor) {
        successor->HandleRequest(event);
    } else {
        std::cout << "ConcreteHandler2: No handler available for error: " << event.errorMessage << std::endl;
    }
}
