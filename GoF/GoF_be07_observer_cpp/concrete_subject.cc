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

#include "concrete_subject.h"

#include <algorithm>

namespace obs_ptn {

ConcreteSubject::ConcreteSubject() : state_("") {}

void ConcreteSubject::Attach(Observer* observer) {
  observers_.push_back(observer);
}

void ConcreteSubject::Detach(Observer* observer) {
  observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

void ConcreteSubject::Notify() {
  for (Observer* observer : observers_) {
    if (observer) {
      observer->Update(this);
    }
  }
}

std::string ConcreteSubject::GetState() const {
  return state_;
}

void ConcreteSubject::SetState(std::string state) {
  state_ = state;
  Notify();
}

} // namespace obs_ptn
