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

#include "unshared_concrete_flyweight.h"

#include <iostream>

void UnsharedConcreteFlyweight::Operation(int extrinsic_state) {
  intrinsic_state_ += extrinsic_state;
  std::cout << "UnsharedConcreteFlyweight: Operation with extrinsic state = " << extrinsic_state << " intrinsic state = " << intrinsic_state_ << std::endl;
}
