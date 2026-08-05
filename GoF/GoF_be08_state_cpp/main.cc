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

#include "concrete_state_a.h"
#include "concrete_state_b.h"
#include "context.h"

int main() {
  std::cout << "GoF State Pattern Example" << std::endl;

  state_ptn::Context context;
  std::unique_ptr<state_ptn::State> state_a =
    std::make_unique<state_ptn::ConcreteStateA>();
  std::unique_ptr<state_ptn::State> state_b =
    std::make_unique<state_ptn::ConcreteStateB>();

  context.SetState(state_a.get());
  context.Request();

  context.SetState(state_b.get());
  context.Request();
  
  return 0;
}
