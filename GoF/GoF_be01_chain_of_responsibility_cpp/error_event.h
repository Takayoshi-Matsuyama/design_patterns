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

#ifndef DESIGN_PTN_BE01_CHAIN_RES_ERROR_EVENT_H_
#define DESIGN_PTN_BE01_CHAIN_RES_ERROR_EVENT_H_

#include <string>

namespace res_chain {

// Represents an error event with a severity level and a message.
struct ErrorEvent {
  // Error severity level (1 for low, 2 for high)
  int error_level;

  // Description of the error
  std::string error_message;
};

} // namespace res_chain

#endif // DESIGN_PTN_BE01_CHAIN_RES_ERROR_EVENT_H_
