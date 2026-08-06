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

#ifndef DESIGN_PTN_BE11_VIS_VISITOR_H_
#define DESIGN_PTN_BE11_VIS_VISITOR_H_

namespace vis_ptn {

// Forward declaration
class ConcreteElementA;
class ConcreteElementB;

// Represents the Visitor interface in the Visitor design pattern.
class Visitor {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~Visitor() = default;

  // Visits a ConcreteElementA object.
  // (1) By this method, Visitor extends ConcreteElementA's functionality
  //     without modifying its structure.
  // (2) By using double dispatch (two overloaded Visit methods),
  //     we can distinguish the visiting target from the type at coding time.
  //     Actual dispatch occurs automatically at runtime.
  virtual void Visit(ConcreteElementA& element) = 0;

  // Visits a ConcreteElementB object.
  virtual void Visit(ConcreteElementB& element) = 0;
};

} // namespace vis_ptn

#endif // DESIGN_PTN_BE11_VIS_VISITOR_H_
