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

#ifndef DESIGN_PTN_BE06_MEM_MEMENTO_H
#define DESIGN_PTN_BE06_MEM_MEMENTO_H

#include <string>

namespace mem_ptn {

// Represents the Memento in the Memento design pattern.
class Memento {
 public:
  // Constructs a Memento with the given state.
  Memento(const std::string& state) : state_(state) {}

  // Returns the state stored in the Memento.
  std::string GetState() const {
    return state_;
  }

  // Sets the state stored in the Memento.
  void SetState(const std::string& state) {
    state_ = state;
  }

 private:
  // The state stored in the Memento.
  std::string state_;
};

}  // namespace mem_ptn

#endif // DESIGN_PTN_BE06_MEM_MEMENTO_H
