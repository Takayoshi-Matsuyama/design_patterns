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

#include "Receiver.h"
#include "ConcreteCommand.h"
#include "Invoker.h"

#include <iostream>
#include <memory>

int main() {
    Receiver receiver;
    std::unique_ptr<Command> command = std::make_unique<ConcreteCommand>(std::make_unique<Receiver>(receiver));
    
    Invoker invoker;
    invoker.SetCommand(std::move(command));
    invoker.ExecuteCommand();
    return 0;
}
