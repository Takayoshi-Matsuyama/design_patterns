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

#include "concrete_strategy_a.h"
#include "concrete_strategy_b.h"
#include "context.h"

int main() {
  std::cout << "GoF Strategy Pattern Example" << std::endl;

  str_ptn::Context context(std::make_unique<str_ptn::ConcreteStrategyA>());
  std::cout << "Result of Strategy A (5 + 3): "
            << context.ExecuteStrategy(5, 3) << std::endl;

  context.SetStrategy(std::make_unique<str_ptn::ConcreteStrategyB>());
  std::cout << "Result of Strategy B (5 - 3): "
            << context.ExecuteStrategy(5, 3) << std::endl;
  
  return 0;
}
