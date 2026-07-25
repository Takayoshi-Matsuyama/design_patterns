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

#ifndef CONCRETE_HANDLER2_H_
#define CONCRETE_HANDLER2_H_

#include "handler.h"

#include <memory>

namespace res_chain {

// Represents a concrete handler in the Chain of Responsibility pattern.
class ConcreteHandler2 : public Handler {
 public:
  // Constructs a ConcreteHandler2 with an optional successor handler.
  // Apply "explicit" to prevent implicit conversions
  // and ensure that the constructor is called with a shared_ptr<Handler> argument.
  explicit ConcreteHandler2(std::shared_ptr<Handler> successor = nullptr);

  // Handles the request based on the error level.
  void HandleRequest(const ErrorEvent& event) override;

 private:
  // Pointer to the next handler in the chain.
  // Note: The successor object can be used in multiple handlers,
  //       so we use std::shared_ptr to manage its lifetime.
  std::shared_ptr<Handler> successor_;
};

} // namespace res_chain

#endif // CONCRETE_HANDLER2_H_
