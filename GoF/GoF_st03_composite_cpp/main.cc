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

#include "composite.h"
#include "leaf.h"

int main() {
  std::cout << "GoF Composite Pattern Example\n";

  // Create composite structure
  std::shared_ptr<cmp_ptn::Component> composite = std::make_shared<cmp_ptn::Composite>();
  composite->Add(std::make_shared<cmp_ptn::Leaf>());
  composite->Add(std::make_shared<cmp_ptn::Leaf>());

  // Execute operation on composite
  composite->Operation();

  return 0;
}
