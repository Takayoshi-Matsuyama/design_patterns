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

#ifndef DESIGN_PTN_ST03_CMP_LEAF_H_
#define DESIGN_PTN_ST03_CMP_LEAF_H_

#include <iostream>

#include "component.h"

namespace cmp_ptn {

// Represents a leaf component in the Composite design pattern.
class Leaf : public Component {
 public:
  // Executes the operation defined by the leaf component.
  void Operation() override {
    std::cout << "Leaf Operation\n";
  }

  // Leaf components do not support adding or removing children.
  void Add(std::shared_ptr<Component> /*component*/) override {
    std::cout << "Cannot add to a leaf\n";
  }

  // Leaf components do not support adding or removing children.
  void Remove(std::shared_ptr<Component> /*component*/) override {
    std::cout << "Cannot remove from a leaf\n";
  }

  // Leaf components do not have children, so this method returns nullptr.
  std::shared_ptr<Component> GetChild(int /*index*/) override {
    std::cout << "Leaf has no children\n";
    return nullptr;
  }
};

} // namespace cmp_ptn

#endif // DESIGN_PTN_ST03_CMP_LEAF_H_
