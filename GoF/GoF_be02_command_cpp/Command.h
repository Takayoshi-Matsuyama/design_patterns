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

#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>

namespace cmd_ptn {

// Represents the Command interface in the Command design pattern.
class Command {
 public:
  // Virtual destructor for proper cleanup of derived classes.
  // This ensures that when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~Command() = default;

  // Executes the command.
  virtual void Execute() = 0;

  // Returns the name of the command.
  virtual std::string GetName() const = 0;
};

} // namespace cmd_ptn

#endif // COMMAND_H_
