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

#ifndef DESIGN_PTN_BE05_MED_CONCRETE_COLLEGUE1_H
#define DESIGN_PTN_BE05_MED_CONCRETE_COLLEGUE1_H

#include <iostream>
#include <string>

#include "collegue.h"
#include "mediator.h"

namespace mediator_ptn {

// Represents a concrete participant in the Mediator pattern.
class ConcreteCollegue1 : public Collegue {
 public:
  // Constructs a ConcreteCollegue1 with a reference to the Mediator.
  ConcreteCollegue1(Mediator* mediator) : mediator_(mediator) {}

  // Sends a message through the Mediator.
  void const Send(const std::string& message) override {
    mediator_->Notify(*this, message);
  }

  // Receives a message and handles it.
  void const Receive(const std::string& message) override {
    std::cout << "ConcreteCollegue1 received: " << message << std::endl;
  }
    
 private:
  // Pointer to the Mediator that facilitates communication between Collegues.
  // Using a pointer for flexibility in the Mediator's lifetime management
  // and avoids ownership issues with smart pointers in this context.
  Mediator* mediator_;
};

} // namespace mediator_ptn

#endif // DESIGN_PTN_BE05_MED_CONCRETE_COLLEGUE1_H
