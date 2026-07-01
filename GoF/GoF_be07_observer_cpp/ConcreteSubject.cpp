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

#include "ConcreteSubject.h"

#include <algorithm>

ConcreteSubject::ConcreteSubject() : _state(0) {}

void ConcreteSubject::Attach(Observer* observer) {
    _observers.push_back(observer);
}

void ConcreteSubject::Detach(Observer* observer) {
    this->_observers.erase(std::remove(this->_observers.begin(), this->_observers.end(), observer), this->_observers.end());
}

void ConcreteSubject::Notify() {
    for (Observer* observer : this->_observers) {
        observer->Update(this);
    }
}

void ConcreteSubject::SetState(int state) {
    this->_state = state;
    Notify();
}

int ConcreteSubject::GetState() const {
    return this->_state;
}
