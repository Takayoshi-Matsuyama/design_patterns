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

#include "concrete_component.h"
#include "concrete_decorator_a.h"
#include "concrete_decorator_b.h"

int main() {
  std::cout << "GoF Decorator Pattern Example\n";

  std::unique_ptr<dec_ptn::Component> component =
    std::make_unique<dec_ptn::ConcreteComponent>();
  std::unique_ptr<dec_ptn::Component> decoratorA =
    std::make_unique<dec_ptn::ConcreteDecoratorA>(component.get());
  std::unique_ptr<dec_ptn::Component> decoratorB =
    std::make_unique<dec_ptn::ConcreteDecoratorB>(decoratorA.get());

  std::cout << "Calling Operation on ConcreteComponent:\n";
  component->Operation();

  std::cout << "\n";

  std::cout << "Calling Operation on ConcreteDecoratorA:\n";
  decoratorA->Operation();

  std::cout << "\n";

  std::cout << "Calling Operation on ConcreteDecoratorB:\n";
  decoratorB->Operation();

  return 0;
}
