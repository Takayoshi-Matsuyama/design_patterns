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

#ifndef DESIGN_PTN_ST02_BRIDGE_ABSTRACTION_H_
#define DESIGN_PTN_ST02_BRIDGE_ABSTRACTION_H_

#include <memory>

#include "implementor.h"

namespace brd_ptn {

// Represents the abstraction in the Bridge pattern.
class Abstraction {
 public:
  // Constructs an Abstraction with the given Implementor.
  explicit Abstraction(std::unique_ptr<Implementor> impl) : impl_(std::move(impl)) {}

  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~Abstraction() = default;

  // Executes operation in abstraction level,
  // which delegates the actual implementation to the Implementor.
  virtual void Operation() {
    impl_->OperationImpl();
  }

 protected:
  // Accessor for the Implementor, allowing derived classes to use it.
  Implementor* GetImpl() const {
    return impl_.get();
  }

 private:
  // Pointer to the Implementor, allowing the Abstraction to delegate
  // the actual work to the Implementor.
  // Note: This class owns the Implementor.
  //       Using std::unique_ptr ensures that the Implementor is properly
  //       managed and cleaned up when the Abstraction is destroyed.
  std::unique_ptr<Implementor> impl_;
};

} // namespace brd_ptn

#endif // DESIGN_PTN_ST02_BRIDGE_ABSTRACTION_H_
