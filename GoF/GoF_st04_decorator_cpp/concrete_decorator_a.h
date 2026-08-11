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

#ifndef DESIGN_PTN_ST04_DEC_CONCRETE_DECORATOR_A_H_
#define DESIGN_PTN_ST04_DEC_CONCRETE_DECORATOR_A_H_

#include <iostream>

#include "component.h"
#include "decorator.h"

namespace dec_ptn {

// Represents a concrete decorator that extends the component's functionality.
class ConcreteDecoratorA : public Decorator {
 public:
  // Constructs a ConcreteDecoratorA with the specified component to decorate.
  explicit ConcreteDecoratorA(Component* component) : Decorator(component) {}

  // Executes the component's operation and additional behavior.
  void Operation() override {
    Decorator::Operation();
    std::cout << "ConcreteDecoratorA added state: " << added_state_ << "\n";
  }

 private:
  // Represents additional state or behavior added by this decorator.
  int added_state_ = 0;
};

} // namespace dec_ptn

#endif // DESIGN_PTN_ST04_DEC_CONCRETE_DECORATOR_A_H_
