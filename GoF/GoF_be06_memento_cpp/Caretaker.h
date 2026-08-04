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

#ifndef DESIGN_PTN_BE06_MEM_CARETAKER_H
#define DESIGN_PTN_BE06_MEM_CARETAKER_H

#include <stdexcept>
#include <vector>

#include "memento.h"

namespace mem_ptn {

// Represents the Caretaker in the Memento design pattern.
class Caretaker {
 public:
  // Constructs a Caretaker with an empty list of Mementos.
  Caretaker() = default;

  // Adds a Memento to the Caretaker's list of Mementos.
  void AddMemento(const Memento& memento) {
    mementos_.push_back(memento);
  }

  // Retrieves a Memento from the Caretaker's list of Mementos by index.
  Memento GetMemento(int index) const {
    if (index < 0 || index >= static_cast<int>(mementos_.size())) {
      throw std::out_of_range("Invalid memento index");
    }
    return mementos_[index];
  }

 private:
  // The list of Mementos stored by the Caretaker.
  std::vector<Memento> mementos_;
};

}  // namespace mem_ptn

#endif // DESIGN_PTN_BE06_MEM_CARETAKER_H
