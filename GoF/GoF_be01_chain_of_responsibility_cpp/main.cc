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

#include "concrete_handler1.h"
#include "concrete_handler2.h"

#include <iostream>
#include <memory>

int main() {
  std::cout << "GoF Chain of Responsibility Pattern Example" << std::endl;

  // Create handlers

  // handler2 has no successor.
  std::shared_ptr<res_chain::ConcreteHandler2> handler2 =
    std::make_shared<res_chain::ConcreteHandler2>();

  // handler1 has the successor handler2
  std::shared_ptr<res_chain::ConcreteHandler1> handler1 =
    std::make_shared<res_chain::ConcreteHandler1>(handler2);

  // Start the chain of responsibility
  
  res_chain::ErrorEvent event1{1, "Low level error occurred."};
  handler1->HandleRequest(event1);

  res_chain::ErrorEvent event2{2, "High level error occurred."};
  handler1->HandleRequest(event2);

  return 0;
}
