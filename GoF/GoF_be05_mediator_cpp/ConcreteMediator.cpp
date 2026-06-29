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

#include "ConcreteMediator.h"

ConcreteMediator::ConcreteMediator() {
    this->_collegue1 = std::make_unique<ConcreteCollegue1>(*this);
    this->_collegue2 = std::make_unique<ConcreteCollegue2>(*this);
}

void ConcreteMediator::Notify(const Collegue& sender, const std::string& message) {
    if (&sender == this->_collegue1.get()) {
        this->_collegue2->Receive(message);
    } else if (&sender == this->_collegue2.get()) {
        this->_collegue1->Receive(message);
    }
}
