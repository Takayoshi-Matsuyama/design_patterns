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

#ifndef DESIGN_PTN_GE01_ABS_FAC_PRODUCT_A1_H_
#define DESIGN_PTN_GE01_ABS_FAC_PRODUCT_A1_H_

#include <iostream>

#include "abstract_product_a.h"

namespace absfac_ptn {

// Represents a concrete product of type A1.
class ProductA1 : public AbstractProductA {
 public:
  // Executes an operation specific to ProductA1.
  void OperationA() const override {
    std::cout << "ProductA1: OperationA executed.\n";
  }
};

} // namespace absfac_ptn

#endif // DESIGN_PTN_GE01_ABS_FAC_PRODUCT_A1_H_
