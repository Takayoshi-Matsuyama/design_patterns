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

#ifndef DESIGN_PTN_ST05_FCD_SUBSYSTEM_B_H_
#define DESIGN_PTN_ST05_FCD_SUBSYSTEM_B_H_

#include <string>

namespace fcd_ptn {

// Represents Subsystem B in the Facade design pattern.
class SubsystemB {
 public:
  // Executes an operation specific to Subsystem B.
  std::string OperationB() {
    return "Operation B result";
  }
};

} // namespace fcd_ptn

#endif // DESIGN_PTN_ST05_FCD_SUBSYSTEM_B_H_
