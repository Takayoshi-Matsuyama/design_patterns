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

#include <iostream>
#include <memory>

#include "concrete_builder.h"
#include "director.h"
#include "product.h"

int main() {
  std::cout << "GoF Builder Pattern Example\n";

  std::unique_ptr<builder_ptn::Builder> builder =
    std::make_unique<builder_ptn::ConcreteBuilder>();

  builder_ptn::Director director(builder.get());
  director.Construct();

  std::unique_ptr<builder_ptn::Product> product = builder->GetResult();
  std::cout << "Product Name: " << product->GetName() << "\n";

  return 0;
}
