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

#ifndef DESIGN_PTN_BE08_STATE_CONTEXT_H_
#define DESIGN_PTN_BE08_STATE_CONTEXT_H_

#include <iostream>

#include "state.h"

namespace state_ptn {

// Represents the context in the State design pattern.
class Context {
 public:
  // Requests the current state to handle the request.
  void Request() {
    if (state_) {
      state_->Handle();
    } else {
      std::cout << "Context: No state set. Cannot handle request." << std::endl;
    }
  }

  // Sets the current state of the context.
  // State's lifecycle is managed outside of this class.
  // So we just refer it through the raw pointer.
  void SetState(State* state) {
    state_ = state;
  }

 private:
  // Pointer to the current state.
  State* state_ = nullptr;
};

}  // namespace state_ptn

#endif // DESIGN_PTN_BE08_STATE_CONTEXT_H_
