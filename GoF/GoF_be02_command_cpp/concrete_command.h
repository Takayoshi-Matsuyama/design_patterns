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

#ifndef CONCRETE_COMMAND_H_
#define CONCRETE_COMMAND_H_

#include "command.h"
#include "receiver.h"

#include <memory>
#include <string>

namespace cmd_ptn {

// Represents a concrete implementation of the Command interface.
class ConcreteCommand : public Command {
 public:
  // Constructs a ConcreteCommand with a name and a reference to a Receiver.
  ConcreteCommand(const std::string& name, Receiver& receiver) : name_(name), receiver_(receiver) {}

  // Executes the command by invoking the action on the receiver.
  void Execute() override;

  // Returns the name of the command.
  std::string GetName() override;

 private:
  // Name of the command.
  std::string name_;

  // Reference to the receiver that will perform the action.
  // Long living object should be kept as a reference to avoid unnecessary copying.
  Receiver& receiver_;
};

} // namespace cmd_ptn

#endif // CONCRETE_COMMAND_H_
