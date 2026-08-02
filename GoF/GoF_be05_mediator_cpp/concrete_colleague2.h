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

#ifndef DESIGN_PTN_BE05_MED_CONCRETE_COLLEAGUE2_H
#define DESIGN_PTN_BE05_MED_CONCRETE_COLLEAGUE2_H

#include <iostream>
#include <string>

#include "colleague.h"
#include "mediator.h"

namespace mediator_ptn {

// Represents a concrete participant in the Mediator pattern.
class ConcreteColleague2 : public Colleague {
 public:
  // Constructs a ConcreteColleague2 with a reference to the Mediator.
  ConcreteColleague2(Mediator* mediator) : mediator_(mediator) {}

  // Sends a message through the Mediator.
  void Send(const std::string& message) const override {
    mediator_->Notify(*this, message);
  }

  // Receives a message and handles it.
  void Receive(const std::string& message) const override {
    std::cout << "ConcreteColleague2 received: " << message << std::endl;
  }
  
 private:
  // Pointer to the Mediator that facilitates communication between Collegues.
  // Using a pointer for flexibility in the Mediator's lifetime management
  // and avoids ownership issues with smart pointers in this context.
  Mediator* mediator_;
};

} // namespace mediator_ptn

#endif // DESIGN_PTN_BE05_MED_CONCRETE_COLLEAGUE2_H
