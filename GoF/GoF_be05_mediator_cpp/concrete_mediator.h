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

#ifndef DESIGN_PTN_BE05_MED_CONCRETE_MEDIATOR_H
#define DESIGN_PTN_BE05_MED_CONCRETE_MEDIATOR_H

#include <memory>

#include "concrete_collegue1.h"
#include "concrete_collegue2.h"
#include "mediator.h"

namespace mediator_ptn {

// Represents a concrete Mediator that facilitates communication between Collegues.
class ConcreteMediator : public Mediator {
 public:
  // Constructs a ConcreteMediator and initializes its Collegues.
  ConcreteMediator();

  // Notifies the appropriate Collegue based on the sender and message.
  void const Notify(const Collegue& sender, const std::string& message) override;

  // Returns a reference to the first Collegue.
  ConcreteCollegue1& GetCollegue1() { return *collegue1_; }

  // Returns a reference to the second Collegue.
  ConcreteCollegue2& GetCollegue2() { return *collegue2_; }

 private:
  // Unique pointers to the Collegues that this Mediator manages.
  std::unique_ptr<ConcreteCollegue1> collegue1_;
  std::unique_ptr<ConcreteCollegue2> collegue2_;
};

} // namespace mediator_ptn

#endif // DESIGN_PTN_BE05_MED_CONCRETE_MEDIATOR_H
