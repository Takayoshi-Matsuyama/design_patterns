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

#ifndef CREATOR_H
#define CREATOR_H

#include "Product.h"

#include <memory>

class Creator {
    public:
        virtual ~Creator() = default;
        virtual std::unique_ptr<Product> FactoryMethod() const = 0;
};

#endif // CREATOR_H
