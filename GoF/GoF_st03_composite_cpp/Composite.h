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

#ifndef DESIGN_PTN_ST03_CMP_COMPOSITE_H_
#define DESIGN_PTN_ST03_CMP_COMPOSITE_H_

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "component.h"

namespace cmp_ptn {

// Represents a composite component in the Composite design pattern.
class Composite : public Component {
 public:
  // Executes the operation defined by the composite component.
  void Operation() override {
    std::cout << "Composite Operation\n";
    for (const auto& child : children_) {
      child->Operation();
    }
  }

  // Adds a child component to the composite.
  void Add(std::shared_ptr<Component> component) override {
    // Use std::move to transfer ownership of the component to the composite.
    // This avoids unnecessary copies and ensures that the composite takes ownership of the component.
    children_.push_back(std::move(component));
  }

  // Removes a child component from the composite.
  void Remove(std::shared_ptr<Component> component) override {
    // Delete the child component with "erase-remove" idiom
    // to avoid memory leaks and dangling pointers.
    children_.erase(
      std::remove(children_.begin(), children_.end(), component),
      children_.end());
  }

  // Retrieves a child component by index.
  std::shared_ptr<Component> GetChild(int index) override {
    if (index < 0 || index >= static_cast<int>(children_.size())) {
      return nullptr;
    }
    return children_[index];
  }

 private:
  // Stores child components of the composite.
  std::vector<std::shared_ptr<Component>> children_;
};

} // namespace cmp_ptn

#endif // DESIGN_PTN_ST03_CMP_COMPOSITE_H_
