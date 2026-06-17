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

#include "Handler.h"
#include "ConcreteHandler1.h"
#include "ConcreteHandler2.h"

#include <iostream>
#include <memory>

int main() {
    std::cout << "GoF Chain of Responsibility Pattern Example" << std::endl;

    // Create handlers
    std::unique_ptr<ConcreteHandler2> handler2 = std::make_unique<ConcreteHandler2>();  // No successor for handler2
    ConcreteHandler1 handler1(std::move(handler2));  // handler2 is the successor of handler1

    // Start the chain of responsibility
    ErrorEvent event1{1, "Low level error occurred."};
    handler1.HandleRequest(event1);

    ErrorEvent event2{2, "High level error occurred."};
    handler1.HandleRequest(event2);

    return 0;
}
