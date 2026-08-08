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

#ifndef DESIGN_PTN_ST01_ADAPTER_ADAPTER_H_
#define DESIGN_PTN_ST01_ADAPTER_ADAPTER_H_

#include <iostream>
#include <memory>

#include "adaptee.h"
#include "target.h"

namespace adp_ptn {

// Represents the adapter in the Adapter design pattern.
class Adapter : public Target {

public:
  // Constucts an Adapter with a unique pointer to an Adaptee.
  explicit Adapter(std::unique_ptr<Adaptee> adaptee) :
    adaptee_(std::move(adaptee)) {}

  // Requests a service from the target interface.
  void Request() override {
    std::string result = adaptee_->SpecificRequest();
    std::cout << "Adapter: Request() -> " << result << "\n";
  }

 private:
  // The adaptee object.
  std::unique_ptr<Adaptee> adaptee_;
};

} // namespace adp_ptn

#endif // DESIGN_PTN_ST01_ADAPTER_ADAPTER_H_
