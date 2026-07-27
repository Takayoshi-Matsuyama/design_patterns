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

#ifndef DESIGN_PTN_BE02_CMD_INVOKER_H_
#define DESIGN_PTN_BE02_CMD_INVOKER_H_

#include <memory>
#include <queue>

#include "command.h"

namespace cmd_ptn {

// Represents the Invoker in the Command design pattern.
class Invoker {
 public:
  // Constructs an Invoker with an empty command queue.
  Invoker() = default;

  // Sets a new command to be executed. The command is added to the queue.
  void SetCommand(std::unique_ptr<Command> new_cmd);

  // Executes the command at the front of the queue and removes it from the queue.
  void ExecuteCommand();

 private:
  // Queue to hold commands to be executed.
  // Initialized as an empty queue in the default constructor.
  std::queue<std::unique_ptr<Command>> cmd_queue_;
};

} // namespace cmd_ptn

#endif // DESIGN_PTN_BE02_CMD_INVOKER_H_
