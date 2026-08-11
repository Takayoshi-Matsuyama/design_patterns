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

#ifndef DESIGN_PTN_ST07_PROXY_PROXY_H_
#define DESIGN_PTN_ST07_PROXY_PROXY_H_

#include <iostream>
#include <memory>

#include "real_subject.h"
#include "subject.h"

namespace prx_ptn {

// Represents the proxy class in the Proxy design pattern.
class Proxy : public Subject {
 public:
  // Constructs a Proxy object.
  Proxy() = default;

  // Executes a request by forwarding it to the real subject.
  void Request() override {
    std::cout << "Proxy: Handling Request. Forwarding to RealSubject.\n";

    if (!real_subject_) {
      // Lazy initialization of the real subject.
      // Note: Practically, the real subject might be created
      //       in a background thread or based on some condition.
      real_subject_ = std::make_unique<RealSubject>();
    }

    // Forward the request to the real subject
    this->real_subject_->Request();
  }

 private:
  // Holds a unique pointer to the real subject,
  // allowing for lazy initialization.
  // Note: Proxy owns the real subject and is responsible for its lifetime.
  std::unique_ptr<Subject> real_subject_ = nullptr;
};

} // namespace prx_ptn

#endif  // DESIGN_PTN_ST07_PROXY_PROXY_H_
