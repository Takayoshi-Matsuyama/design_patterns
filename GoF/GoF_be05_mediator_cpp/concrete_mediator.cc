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

#include "concrete_mediator.h"

namespace mediator_ptn {

ConcreteMediator::ConcreteMediator() {
  collegue1_ = std::make_unique<ConcreteCollegue1>(this);
  collegue2_ = std::make_unique<ConcreteCollegue2>(this);
}

void const ConcreteMediator::Notify(const Collegue& sender, const std::string& message) {
  if (&sender == collegue1_.get()) {
    collegue2_->Receive(message);
  } else if (&sender == collegue2_.get()) {
    collegue1_->Receive(message);
  }
}

} // namespace mediator_ptn
