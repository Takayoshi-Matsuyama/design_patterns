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

#include "concrete_prototype1.h"
#include "concrete_prototype2.h"

#include <iostream>

int main() {
  std::cout << "GoF Prototype Pattern Example\n";

  prt_ptn::ConcretePrototype1 prototype1;
  prototype1.SetName("Prototype 1");
  prt_ptn::ConcretePrototype1 clone1 =
    *dynamic_cast<prt_ptn::ConcretePrototype1*>(prototype1.Clone().get());
  std::cout << "Cloned ConcretePrototype1: " << clone1.GetName() << "\n";

  prt_ptn::ConcretePrototype2 prototype2;
  prototype2.SetValue(42.0);
  prt_ptn::ConcretePrototype2 clone2 =
    *dynamic_cast<prt_ptn::ConcretePrototype2*>(prototype2.Clone().get());
  std::cout << "Cloned ConcretePrototype2: " << clone2.GetValue() << "\n";

  return 0;
}
