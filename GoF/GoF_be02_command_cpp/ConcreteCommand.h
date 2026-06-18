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

#ifndef CONCRETE_COMMAND_H
#define CONCRETE_COMMAND_H

#include "Command.h"
#include "Receiver.h"

#include <memory>
#include <string>

class ConcreteCommand : public Command {
    public:
        ConcreteCommand(const std::string& name, Receiver& receiver) : receiver(receiver) {
            this->name = name;
        }
        void Execute() override;
        std::string GetName() override;
    private:
        std::string name;
        Receiver& receiver;  // Long living object should be kept as a reference to avoid unnecessary copying
};

#endif // CONCRETE_COMMAND_H
