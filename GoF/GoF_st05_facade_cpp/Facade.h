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

#ifndef DESIGN_PTN_ST05_FCD_FACADE_H_
#define DESIGN_PTN_ST05_FCD_FACADE_H_

#include <string>
#include <memory>

#include "subsystem_a.h"
#include "subsystem_b.h"
#include "subsystem_c.h"

namespace fcd_ptn {

// Represents a facade in the Facade design pattern.
class Facade {
 public:
  // Constructs a new Facade object.
  Facade() : subsystem_a_(std::make_unique<SubsystemA>()),
             subsystem_b_(std::make_unique<SubsystemB>()),
             subsystem_c_(std::make_unique<SubsystemC>()) {}
  
  // Executes an operation that involves multiple subsystems.
  std::string Operation() const {
    std::string result;
    result += subsystem_a_->OperationA();
    result += " ";
    result += subsystem_b_->OperationB();
    result += " ";
    result += subsystem_c_->OperationC();
    return result;
  }

 private:
  // Subsystem A that the facade interacts with.
  std::unique_ptr<SubsystemA> subsystem_a_;

  // Subsystem B that the facade interacts with.
  std::unique_ptr<SubsystemB> subsystem_b_;

  // Subsystem C that the facade interacts with.
  std::unique_ptr<SubsystemC> subsystem_c_;
};

} // namespace fcd_ptn

#endif // DESIGN_PTN_ST05_FCD_FACADE_H_
