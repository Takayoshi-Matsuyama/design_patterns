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

  std::shared_ptr<Flyweight> flyweight_1 = factory.GetFlyweight(1);
  std::shared_ptr<Flyweight> flyweight_2a = factory.GetFlyweight(2);
  std::shared_ptr<Flyweight> flyweight_2b = factory.GetFlyweight(2);
  std::shared_ptr<Flyweight> unshared_flyweight = factory.GetUnsharedFlyweight(3);

  flyweight_1->Operation(10);
  flyweight_2a->Operation(20);
  flyweight_2b->Operation(30);
  unshared_flyweight->Operation(40);

  std::cout << "flyweight_2a and flyweight_2b are " << (flyweight_2a == flyweight_2b ? "the same instance" : "different instances") << std::endl;
  std::cout << "flyweight_2a address: " << flyweight_2a.get() << std::endl;
  std::cout << "flyweight_2b address: " << flyweight_2b.get() << std::endl;
  
  return 0;
}
