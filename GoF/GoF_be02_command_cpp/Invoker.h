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

#ifndef INVOKER_H_
#define INVOKER_H_

#include "command.h"

#include <memory>
#include <queue>

namespace cmd_ptn {

class Invoker {
 public:
  Invoker();
  void SetCommand(std::unique_ptr<Command> new_cmd);
  void ExecuteCommand();

 private:
  std::queue<std::unique_ptr<Command>> cmd_queue_;
};

}  // namespace cmd_ptn

#endif // INVOKER_H_
