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

#ifndef DESIGN_PTN_BE06_MEM_ORIGINATOR_H_
#define DESIGN_PTN_BE06_MEM_ORIGINATOR_H_

#include <string>

#include "memento.h"

namespace mem_ptn {

// Represents the Originator in the Memento design pattern.
class Originator {
 public:
  // Constructs an Originator with an initial state.
  Originator() = default;

  // Gets the state of the Originator.
  std::string GetState() const {
    return state_;
  }

  // Sets the state of the Originator.
  void SetState(const std::string& state) {
    state_ = state;
  }

  // Creates a Memento that captures the current state of the Originator.
  Memento CreateMemento() const {
    return Memento(state_);
  }

  // Restores the state of the Originator from a Memento.
  void SetMemento(const Memento& memento) {
    state_ = memento.GetState();
  }

 private:
  // The current state of the Originator.
  std::string state_;
};

}	// namespace mem_ptn

#endif // DESIGN_PTN_BE06_MEM_ORIGINATOR_H_
