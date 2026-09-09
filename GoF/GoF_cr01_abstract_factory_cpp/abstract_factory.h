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

#ifndef DESIGN_PTN_GE01_ABS_FAC_ABSTRACT_FACTORY_H_
#define DESIGN_PTN_GE01_ABS_FAC_ABSTRACT_FACTORY_H_

#include <memory>

#include "abstract_product_a.h"
#include "abstract_product_b.h"

namespace absfac_ptn {

// Represents the abstract factory interface.
class AbstractFactory {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~AbstractFactory() = default;

  // Creates a product of type A.
  virtual std::unique_ptr<AbstractProductA> CreateProductA() const = 0;

  // Creates a product of type B.
  virtual std::unique_ptr<AbstractProductB> CreateProductB() const = 0;
};

} // namespace absfac_ptn

#endif // DESIGN_PTN_GE01_ABS_FAC_ABSTRACT_FACTORY_H_
