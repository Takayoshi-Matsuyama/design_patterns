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

#include "concrete_mediator.h"

int main() {
  std::cout << "GoF Mediator Pattern Example" << std::endl;

  mediator_ptn::ConcreteMediator mediator;
  mediator.GetColleague1().Send("Hello from Colleague 1");
  mediator.GetColleague2().Send("Hello from Colleague 2");

  return 0;
}
