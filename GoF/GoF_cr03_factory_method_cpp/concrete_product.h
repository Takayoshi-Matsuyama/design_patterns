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

#ifndef DESIGN_PTN_GEN03_FACTORY_METHOD_CONCRETE_PRODUCT_H_
#define DESIGN_PTN_GEN03_FACTORY_METHOD_CONCRETE_PRODUCT_H_

#include <iostream>

#include "product.h"

namespace facmtd_ptn {

// Represents a concrete product in the Factory Method pattern.
class ConcreteProduct : public Product {
 public:
  // Executes an operation specific to the concrete product.
  void Operation() override {
    std::cout << "ConcreteProduct Operation\n";
  }
};

} // namespace facmtd_ptn

#endif // DESIGN_PTN_GEN03_FACTORY_METHOD_CONCRETE_PRODUCT_H_
