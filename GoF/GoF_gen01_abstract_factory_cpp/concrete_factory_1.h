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

#ifndef DESIGN_PTN_GE01_ABS_FAC_CONCRETE_FACTORY1_H_
#define DESIGN_PTN_GE01_ABS_FAC_CONCRETE_FACTORY1_H_

#include <memory>

#include "abstract_factory.h"
#include "product_a1.h"
#include "product_b1.h"

namespace absfac_ptn {

class ConcreteFactory1 : public AbstractFactory {
    public:
        std::unique_ptr<AbstractProductA> CreateProductA() override {
            return std::make_unique<ProductA1>();
        }
        std::unique_ptr<AbstractProductB> CreateProductB() override {
            return std::make_unique<ProductB1>();
        }
};

} // namespace absfac_ptn

#endif // DESIGN_PTN_GE01_ABS_FAC_CONCRETE_FACTORY1_H_
