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

#ifndef DESIGN_PTN_ST03_CMP_COMPONENT_H_
#define DESIGN_PTN_ST03_CMP_COMPONENT_H_

#include <memory>

namespace cmp_ptn {

// Represents the component interface in the Composite design pattern.
class Component {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~Component() = default;

  // Executes the operation defined by the component.
  virtual void Operation() = 0;

  // Adds a child component to the composite.
  virtual void Add(std::shared_ptr<Component> component) = 0;

  // Removes a child component from the composite.
  virtual void Remove(std::shared_ptr<Component> component) = 0;

  // Retrieves a child component by index.
  // Returns nullptr if the index is invalid.
  virtual std::shared_ptr<Component> GetChild(int index) = 0;
};

} // namespace cmp_ptn

#endif // DESIGN_PTN_ST03_CMP_COMPONENT_H_
