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

#include "invoker.h"

#include <iostream>

namespace cmd_ptn {

Invoker::Invoker() {
  this->cmd_queue_ = std::queue<std::unique_ptr<Command>>();
}

void Invoker::SetCommand(std::unique_ptr<Command> new_cmd) {
  this->cmd_queue_.push(std::move(new_cmd));

  std::cout << "Queue size: " << this->cmd_queue_.size() << std::endl;
}

void Invoker::ExecuteCommand() {
  if (!this->cmd_queue_.empty()) {
    std::cout << "Executing " << cmd_queue_.front()->GetName() << " ..." << std::endl;
    cmd_queue_.front()->Execute();
    cmd_queue_.pop();

    std::cout << "Remaining queue size: " << cmd_queue_.size() << std::endl;
  }
}

} // namespace cmd_ptn
