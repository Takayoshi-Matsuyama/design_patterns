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

#include "Facade.h"
#include "SubsystemA.h"
#include "SubsystemB.h"
#include "SubsystemC.h"

#include <string>
#include <memory>

Facade::Facade() : subsystemA(std::make_unique<SubsystemA>()),
                   subsystemB(std::make_unique<SubsystemB>()),
                   subsystemC(std::make_unique<SubsystemC>()) {}

std::string Facade::Operation() {
    std::string result;
    result += subsystemA->OperationA();
    result += " ";
    result += subsystemB->OperationB();
    result += " ";
    result += subsystemC->OperationC();
    return result;
}
