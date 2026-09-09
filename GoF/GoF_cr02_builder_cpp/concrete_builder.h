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

#ifndef DESIGN_PTN_GEN02_BUILDER_CONCRETE_BUILDER_H_
#define DESIGN_PTN_GEN02_BUILDER_CONCRETE_BUILDER_H_

#include <memory>

#include "builder.h"

namespace builder_ptn {

// Represents a concrete builder that constructs a specific product.
class ConcreteBuilder : public Builder {
 public:

  // Builds a part of the product.
  void BuildPart() override {
    product_ = std::make_unique<Product>("Sample Product");
  }

  // Returns the final product.
  std::unique_ptr<Product> GetResult() override {
    return std::move(product_);
  }

 private:
  // Holds the product being built.
  // Using std::unique_ptr ensures that
  // the product is properly managed and automatically cleaned up
  // when it goes out of scope.
  std::unique_ptr<Product> product_;
};

} // namespace builder_ptn

#endif // DESIGN_PTN_GEN02_BUILDER_CONCRETE_BUILDER_H_
