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

#include "ConcretePrototype1.h"

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1& other) {
    this->_name = other._name;
}

std::unique_ptr<Prototype> ConcretePrototype1::Clone() const {
    return std::make_unique<ConcretePrototype1>(*this);
}

std::string ConcretePrototype1::GetName() const {
    return this->_name;
}

void ConcretePrototype1::SetName(const std::string& name) {
    this->_name = name;
}
