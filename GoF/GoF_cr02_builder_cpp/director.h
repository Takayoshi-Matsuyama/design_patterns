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

#ifndef DESIGN_PTN_GEN02_BUILDER_DIRECTOR_H_
#define DESIGN_PTN_GEN02_BUILDER_DIRECTOR_H_

#include "builder.h"

namespace builder_ptn {

// Represents the director that orchestrates the construction process.
class Director {
 public:
  // Constructs a Director with a given builder.
  explicit Director(Builder* builder) : builder_(builder) {}

  // Constructs the product by invoking the builder's BuildPart method.
  void Construct() {
    builder_->BuildPart();
  }

 private:
  // Holds a pointer to the builder used for constructing the product.
  // The Director does not own the builder;
  // it only uses it to construct the product.
  Builder* builder_;
};

} // namespace builder_ptn

#endif // DESIGN_PTN_GEN02_BUILDER_DIRECTOR_H_
