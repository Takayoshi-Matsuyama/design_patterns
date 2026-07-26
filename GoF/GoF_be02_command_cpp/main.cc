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

#include "receiver.h"
#include "concrete_command.h"
#include "invoker.h"

#include <iostream>
#include <memory>

int main() {
  cmd_ptn::Receiver receiver;
  std::unique_ptr<cmd_ptn::Command> command1 = std::make_unique<cmd_ptn::ConcreteCommand>("Command1", receiver);
  std::unique_ptr<cmd_ptn::Command> command2 = std::make_unique<cmd_ptn::ConcreteCommand>("Command2", receiver);
  
  cmd_ptn::Invoker invoker;
  invoker.SetCommand(std::move(command1));
  invoker.SetCommand(std::move(command2));
  invoker.ExecuteCommand();
  invoker.ExecuteCommand();
  return 0;
}
