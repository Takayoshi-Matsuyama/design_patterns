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

#ifndef DESIGN_PTN_BE08_STATE_STATE_H_
#define DESIGN_PTN_BE08_STATE_STATE_H_

namespace state_ptn {

// Represents the abstract state interface in the State design pattern.
class State {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~State() {}

  // Handles the request based on the state.
  virtual void Handle() = 0;
};

}  // namespace state_ptn

#endif // DESIGN_PTN_BE08_STATE_STATE_H_
