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

#ifndef CONCRETE_HANDLER1_H
#define CONCRETE_HANDLER1_H

#include <memory>
using namespace std;

#include "Handler.h"

class ConcreteHandler1 : public Handler {
private:
    unique_ptr<Handler> successor;  // Pointer to the next handler in the chain
public:
    ConcreteHandler1(unique_ptr<Handler> successor = nullptr);
    void HandleRequest() override;
};

#endif // CONCRETE_HANDLER1_H
