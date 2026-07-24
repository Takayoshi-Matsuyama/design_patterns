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

#include "flyweight_factory.h"

#include "concrete_flyweight.h"
#include "unshared_concrete_flyweight.h"

namespace flyweight_pattern {

std::shared_ptr<Flyweight> FlyweightFactory::GetFlyweight(int key) {
  auto it = flyweights_.find(key);
  if (it != flyweights_.end()) {
    return it->second;
  } else {
    auto flyweight = std::make_shared<ConcreteFlyweight>();
    flyweights_[key] = flyweight;
    return flyweight;
  }
}

std::shared_ptr<Flyweight> FlyweightFactory::GetUnsharedFlyweight(int key) {
  return std::make_shared<UnsharedConcreteFlyweight>();
}

} // namespace flyweight_pattern
