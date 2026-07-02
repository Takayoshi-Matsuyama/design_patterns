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

#ifndef CONCRETE_SUBJECT_H
#define CONCRETE_SUBJECT_H

#include "Subject.h"

#include <vector>
#include <string>

class ConcreteSubject : public Subject {
    public:
        ConcreteSubject();
        void Attach(Observer* observer) override;
        void Detach(Observer* observer) override;
        void Notify() override;
        std::string GetState() const override;

        // Additional methods specific to ConcreteSubject
        void SetState(std::string state);
       

    private:
        std::string _state;
        std::vector<Observer*> _observers;
};

#endif // CONCRETE_SUBJECT_H
