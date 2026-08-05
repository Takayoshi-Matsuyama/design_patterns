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

#ifndef DESIGN_PTN_BE08_STATE_CONCRETE_STATE_A_H_
#define DESIGN_PTN_BE08_STATE_CONCRETE_STATE_A_H_

#include <iostream>

#include "state.h"

namespace state_ptn {

// Represents a concrete state in the State design pattern.
class ConcreteStateA : public State {
 public:
  // Handles the request specific to ConcreteStateA.
  void Handle() override {
    std::cout << "ConcreteStateA: Handling request." << std::endl;
  }
};

}  // namespace state_ptn

#endif // DESIGN_PTN_BE08_STATE_CONCRETE_STATE_A_H_
