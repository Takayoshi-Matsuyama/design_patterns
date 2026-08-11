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

#ifndef DESIGN_PTN_ST04_DEC_DECORATOR_H_
#define DESIGN_PTN_ST04_DEC_DECORATOR_H_

#include "component.h"

namespace dec_ptn {

// Represents the base class for decorators in the Decorator pattern.
class Decorator : public Component {
 public:
  // Constructs a Decorator with the specified component to decorate.
  Decorator(Component* component) : component_(component) {}

  // Executes the operation defined by the component.
  // Note: Additional behavior will be added by derived decorators.
  void Operation() override {
    if (component_) {
      component_->Operation();
    }
  }

 private:
  // Pointer to the component being decorated.
  // Note: Decorator does not own the component; Just holds the pointer.
  //       The component's lifetime is managed by outside of this class.
  Component* component_;
};

} // namespace dec_ptn

#endif // DESIGN_PTN_ST04_DEC_DECORATOR_H_
