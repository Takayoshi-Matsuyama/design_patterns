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

#ifndef DESIGN_PTN_BE11_VIS_ELEMENT_H_
#define DESIGN_PTN_BE11_VIS_ELEMENT_H_

#include <string>

namespace vis_ptn {

// Forward declaration
class Visitor;

// Represents the Element interface in the Visitor design pattern.
class Element {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~Element() = default;

  // Accepts a Visitor object,
  // allowing it to perform operations on the Element.
  virtual void Accept(Visitor& visitor) = 0;

  // Returns the name of the Element.
  virtual std::string GetName() const = 0;
};

} // namespace vis_ptn

#endif // DESIGN_PTN_BE11_VIS_ELEMENT_H_
