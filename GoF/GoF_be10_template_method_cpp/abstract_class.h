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

#ifndef DESIGN_PTN_BE10_TEMP_METHOD_ABSTRACT_CLASS_H_
#define DESIGN_PTN_BE10_TEMP_METHOD_ABSTRACT_CLASS_H_

namespace tmpmtd_ptn {

// Represents the abstract class in the Template Method pattern.
class AbstractClass {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~AbstractClass() = default;

  // Executes the template method.
  // This method is NOT virtual
  // because it defines the framework of the algorithm.
  void Template_Method() const {
    PrimitiveOperation1();
    PrimitiveOperation2();
  }

 protected:
  // Executes the primitive operation #1.
  // This method is virtual
  // because it allows customization in derived classes.
  virtual void PrimitiveOperation1() const = 0;

  // Executes the primitive operation #2.
  // This method is virtual
  // because it allows customization in derived classes.
  virtual void PrimitiveOperation2() const = 0;
};

} // namespace tmpmtd_ptn

#endif // DESIGN_PTN_BE10_TEMP_METHOD_ABSTRACT_CLASS_H_
