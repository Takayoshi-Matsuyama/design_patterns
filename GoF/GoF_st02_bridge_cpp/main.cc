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

#include "concrete_implementor_a.h"
#include "concrete_implementor_b.h"

#include "refined_abstraction.h"

#include <iostream>

#include "abstraction.h"

int main() {
  std::cout << "GoF Bridge Pattern Example\n";

  brd_ptn::RefinedAbstraction abstractionA(
    std::make_unique<brd_ptn::ConcreteImplementorA>());
  abstractionA.Operation();

  brd_ptn::RefinedAbstraction abstractionB(
    std::make_unique<brd_ptn::ConcreteImplementorB>());
  abstractionB.Operation();

  return 0;
}
