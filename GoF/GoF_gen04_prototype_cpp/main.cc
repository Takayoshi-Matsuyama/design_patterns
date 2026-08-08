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

#include <iostream>
#include <memory>

#include "concrete_prototype1.h"
#include "concrete_prototype2.h"

int main() {
  std::cout << "GoF Prototype Pattern Example\n";

  prt_ptn::ConcretePrototype1 prototype1;
  prototype1.SetName("Prototype 1");

  std::unique_ptr<prt_ptn::Prototype> cloned_base1 = prototype1.Clone();
  auto* clone1 = dynamic_cast<prt_ptn::ConcretePrototype1*>(cloned_base1.get());
  if (clone1) {
    std::cout << "Cloned ConcretePrototype1: " << clone1->GetName() << "\n";
  } else {
    std::cerr << "Failed to clone ConcretePrototype1\n";
  }

  prt_ptn::ConcretePrototype2 prototype2;
  prototype2.SetValue(42.0);

  std::unique_ptr<prt_ptn::Prototype> cloned_base2 = prototype2.Clone();
  auto* clone2 = dynamic_cast<prt_ptn::ConcretePrototype2*>(cloned_base2.get());
  if (clone2) {
    std::cout << "Cloned ConcretePrototype2: " << clone2->GetValue() << "\n";
  } else {
    std::cerr << "Failed to clone ConcretePrototype2\n";
  }

  return 0;
}
