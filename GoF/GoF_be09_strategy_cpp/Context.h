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

#ifndef DESIGN_PTN_BE09_STR_CONTEXT_H_
#define DESIGN_PTN_BE09_STR_CONTEXT_H_

#include "strategy.h"

#include <memory>

// Represents the Context class that maintains a reference to a Strategy.
class Context {
 public:
  // Constructs a Context with an optional Strategy.
  Context(std::unique_ptr<Strategy> strategy = nullptr)
    : strategy_(std::move(strategy)) {}
  
  // Disposes of the Context and its associated Strategy.
  ~Context() = default;

  // Executes the algorithm defined by the current Strategy.
  double ExecuteStrategy(double a, double b) {
    if (strategy_) {
      return strategy_->AlgorithmInterface(a, b);
    }

    // Default behavior if no strategy is set
    return 0.0;
  }

 private:
  // The current Strategy used by the Context.
  std::unique_ptr<Strategy> strategy_ = nullptr;
};

#endif // DESIGN_PTN_BE09_STR_CONTEXT_H_
