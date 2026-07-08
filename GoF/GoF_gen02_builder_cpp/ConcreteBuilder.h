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

#ifndef CONCRETE_BUILDER_H
#define CONCRETE_BUILDER_H

#include "Builder.h"

class ConcreteBuilder : public Builder {
    public:
        ConcreteBuilder() = default;
        ~ConcreteBuilder() override = default;
        void BuildPart() override;
        std::unique_ptr<Product> GetResult() override;
    private:
        std::unique_ptr<Product> _product; // The product being built
};

#endif // CONCRETE_BUILDER_H
