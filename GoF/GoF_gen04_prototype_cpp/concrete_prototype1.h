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

#ifndef DESIGN_PTN_GEN04_PROTOTYPE_CONCRETE_PROTOTYPE_1_H_
#define DESIGN_PTN_GEN04_PROTOTYPE_CONCRETE_PROTOTYPE_1_H_

#include <memory>
#include <string>

#include "prototype.h"

namespace prt_ptn {

// Represents a concrete implementation of the Prototype interface.
class ConcretePrototype1 : public Prototype {
 public:
  // Constructs a new ConcretePrototype1 object with default values.
  ConcretePrototype1() = default;

  // Constructs a new ConcretePrototype1 object.
  // Note: 'explicit' is not used here to allow implicit copy construction.
  ConcretePrototype1(const ConcretePrototype1& other) {
    name_ = other.name_;
  }

  // Clones the current object and returns a unique pointer to the new object.
  std::unique_ptr<Prototype> Clone() const override {
    return std::make_unique<ConcretePrototype1>(*this);
  }

  // Returns the name of this object.
  std::string GetName() const {
    return name_;
  }

  // Sets the name of this object.
  void SetName(const std::string& name){
    name_ = name;
  }

 private:
  // The name of this object.
  std::string name_ = "";
};

} // namespace prt_ptn

#endif // DESIGN_PTN_GEN04_PROTOTYPE_CONCRETE_PROTOTYPE_1_H_
