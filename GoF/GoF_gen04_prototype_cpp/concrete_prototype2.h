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

#ifndef DESIGN_PTN_GEN04_PROTOTYPE_CONCRETE_PROTOTYPE_2_H_
#define DESIGN_PTN_GEN04_PROTOTYPE_CONCRETE_PROTOTYPE_2_H_

#include <memory>

#include "prototype.h"

namespace prt_ptn {

// Represents a concrete implementation of the Prototype interface.
class ConcretePrototype2 : public Prototype {
 public:
  // Constructs a new ConcretePrototype2 object with default values.
  ConcretePrototype2() = default;

  // Constructs a new ConcretePrototype2 object.
  ConcretePrototype2(const ConcretePrototype2& other) {
    value_ = other.value_;
  }

  // Clones the current object and returns a unique pointer to the new object.
  std::unique_ptr<Prototype> Clone() const override {
    return std::make_unique<ConcretePrototype2>(*this);
  }

  // Returns the value of this object.
  double GetValue() const {
    return value_;
  }

  // Sets the value of this object.
  void SetValue(double value) {
    value_ = value;
  }

 private:
  // The value of this object.
  double value_ = 0.0;
};

} // namespace prt_ptn

#endif // DESIGN_PTN_GEN04_PROTOTYPE_CONCRETE_PROTOTYPE_2_H_
