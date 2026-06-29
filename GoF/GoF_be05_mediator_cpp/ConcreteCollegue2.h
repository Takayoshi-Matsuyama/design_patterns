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

#ifndef CONCRETE_COLLEGUE2_H
#define CONCRETE_COLLEGUE2_H

#include "Collegue.h"
#include "Mediator.h"

#include <string>
#include <iostream>

class ConcreteCollegue2 : public Collegue {
    public:
        ConcreteCollegue2(Mediator& mediator) : _mediator(mediator) {}

        void Send(const std::string& message) override {
            this->_mediator.Notify(*this, message);
        }

        void Receive(const std::string& message) override {
            // Handle received message
            std::cout << "ConcreteCollegue2 received: " << message << std::endl;
        }
        
    private:
        Mediator& _mediator;
};

#endif // CONCRETE_COLLEGUE2_H
