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

#include "concrete_handler2.h"

#include <iostream>
#include <memory>

namespace res_chain {

ConcreteHandler2::ConcreteHandler2(std::shared_ptr<Handler> successor) : successor_(std::move(successor)) {
  // None
}

void ConcreteHandler2::HandleRequest(const ErrorEvent& event) {
  std::cout << "ConcreteHandler2 handling request." << std::endl;
  if (event.error_level == 2) {
    std::cout << "ConcreteHandler2: Handled high level error: " << event.error_message << std::endl;
  } else if (successor_) {
    successor_->HandleRequest(event);
  } else {
    std::cout << "ConcreteHandler2: No handler available for error: " << event.error_message << std::endl;
  }
}

} // namespace res_chain
