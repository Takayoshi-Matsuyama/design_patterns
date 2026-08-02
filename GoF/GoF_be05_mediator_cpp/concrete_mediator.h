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

#include "concrete_colleague1.h"
#include "concrete_colleague2.h"
#include "mediator.h"

namespace mediator_ptn {

// Represents a concrete Mediator that facilitates communication between Collegues.
class ConcreteMediator : public Mediator {
 public:
  // Constructs a ConcreteMediator and initializes its Collegues.
  ConcreteMediator();

  // Notifies the appropriate Colleague based on the sender and message.
  void Notify(const Colleague& sender, const std::string& message) const override;

  // Returns a reference to the first Colleague.
  ConcreteColleague1& GetColleague1() { return *colleague1_; }

  // Returns a reference to the second Colleague.
  ConcreteColleague2& GetColleague2() { return *colleague2_; }

 private:
  // Unique pointers to the Collegues that this Mediator manages.
  std::unique_ptr<ConcreteColleague1> colleague1_;
  std::unique_ptr<ConcreteColleague2> colleague2_;
};

} // namespace mediator_ptn

#endif // DESIGN_PTN_BE05_MED_CONCRETE_MEDIATOR_H
