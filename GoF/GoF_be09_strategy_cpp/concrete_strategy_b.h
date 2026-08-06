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

#ifndef DESIGN_PTN_BE09_STR_CONCRETE_STRATEGY_B_H_
#define DESIGN_PTN_BE09_STR_CONCRETE_STRATEGY_B_H_

#include "strategy.h"

// Represents a concrete implementation of the Strategy interface.
class ConcreteStrategyB : public Strategy {
 public:
  // Executes the algorithm for ConcreteStrategyB.
  double AlgorithmInterface(double a, double b) override {
    return a - b;
  }
};
#endif // DESIGN_PTN_BE09_STR_CONCRETE_STRATEGY_B_H_
