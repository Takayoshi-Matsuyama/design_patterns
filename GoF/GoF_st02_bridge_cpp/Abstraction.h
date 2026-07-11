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

#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include "Implementor.h"

#include <memory>

class Abstraction {
    public:
        Abstraction(std::shared_ptr<Implementor> impl) : impl(std::move(impl)) {}
        virtual ~Abstraction() = default;
        virtual void Operation() = 0;
    protected:
        std::shared_ptr<Implementor> impl;
};

#endif // ABSTRACTION_H
