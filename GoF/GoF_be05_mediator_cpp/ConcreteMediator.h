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

#ifndef CONCRETE_MEDIATOR_H
#define CONCRETE_MEDIATOR_H

#include "Mediator.h"
#include "ConcreteCollegue1.h"
#include "ConcreteCollegue2.h"

#include <memory>

class ConcreteMediator : public Mediator {
    public:
        ConcreteMediator();
        void Notify(const Collegue& sender, const std::string& message) override;
        ConcreteCollegue1& GetCollegue1() { return *this->_collegue1; }
        ConcreteCollegue2& GetCollegue2() { return *this->_collegue2; }

    private:
        std::unique_ptr<ConcreteCollegue1> _collegue1;
        std::unique_ptr<ConcreteCollegue2> _collegue2;
};

#endif // CONCRETE_MEDIATOR_H
