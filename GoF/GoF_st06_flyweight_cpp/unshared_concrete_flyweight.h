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

#ifndef UNSHARED_CONCRETE_FLYWEIGHT_H_
#define UNSHARED_CONCRETE_FLYWEIGHT_H_

#include "flyweight.h"

// Represents an unshared concrete flyweight.
class UnsharedConcreteFlyweight : public Flyweight {
 public:
  // Implements the Flyweight interface method to perform an operation with extrinsic state.
  void Operation(int extrinsic_state) override;

 private:
  // Intrinsic state of the unshared concrete flyweight.
  int intrinsic_state_ = 0;
};

#endif // UNSHARED_CONCRETE_FLYWEIGHT_H_
