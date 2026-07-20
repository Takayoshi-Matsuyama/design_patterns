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

#include "flyweight.h"
#include "flyweight_factory.h"

#include <iostream>
#include <memory>

int main() {
    std::cout << "GoF Flyweight Pattern Example" << std::endl;

    FlyweightFactory factory;

    std::shared_ptr<Flyweight> flyweight1 = factory.GetFlyweight(1);
    std::shared_ptr<Flyweight> flyweight2A = factory.GetFlyweight(2);
    std::shared_ptr<Flyweight> flyweight2B = factory.GetFlyweight(2);
    std::shared_ptr<Flyweight> unsharedFlyweight = factory.GetUnsharedFlyweight(3);

    flyweight1->Operation(10);
    flyweight2A->Operation(20);
    flyweight2B->Operation(30);
    unsharedFlyweight->Operation(40);

    std::cout << "flyweight2A and flyweight2B are " << (flyweight2A == flyweight2B ? "the same instance" : "different instances") << std::endl;
    std::cout << "flyweight2A address: " << flyweight2A.get() << std::endl;
    std::cout << "flyweight2B address: " << flyweight2B.get() << std::endl;
    
    return 0;
}
