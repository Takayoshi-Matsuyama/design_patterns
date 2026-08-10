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

#ifndef DESIGN_PTN_ST02_BRIDGE_CONCRETE_IMPLEMENTOR_A_H_
#define DESIGN_PTN_ST02_BRIDGE_CONCRETE_IMPLEMENTOR_A_H_

#include <iostream>

#include "implementor.h"

namespace brd_ptn {

// Represents a concrete implementor in the Bridge pattern.
class ConcreteImplementorA : public Implementor {
 public:
  // Executes the operation in the concrete level for ConcreteImplementorA.
  void OperationImpl() override {
    std::cout << "ConcreteImplementorA: OperationImpl called.\n";
  }
};

} // namespace brd_ptn

#endif // DESIGN_PTN_ST02_BRIDGE_CONCRETE_IMPLEMENTOR_A_H_
