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

#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

#include <iostream>

#include <memory>

int main() {
    
    std::cout << "GoF Decorator Pattern Example" << std::endl;

    std::unique_ptr<Component> component = std::make_unique<ConcreteComponent>();
    std::unique_ptr<Component> decoratorA = std::make_unique<ConcreteDecoratorA>(component.get());
    std::unique_ptr<Component> decoratorB = std::make_unique<ConcreteDecoratorB>(decoratorA.get());

    std::cout << "Calling Operation on ConcreteComponent:" << std::endl;
    component->Operation();

    std::cout << "Calling Operation on ConcreteDecoratorA:" << std::endl;
    decoratorA->Operation();

    std::cout << "Calling Operation on ConcreteDecoratorB:" << std::endl;
    decoratorB->Operation();

    return 0;
}
