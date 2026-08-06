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

#include "abstract_factory.h"
#include "concrete_factory_1.h"
#include "concrete_factory_2.h"
#include "abstract_product_a.h"
#include "abstract_product_b.h"

#include <iostream>
#include <memory>

int main() {
    
    std::cout << "GoF Abstract Factory Pattern Example" << std::endl;

    std::unique_ptr<absfac_ptn::AbstractFactory> factory1 = std::make_unique<absfac_ptn::ConcreteFactory1>();
    std::unique_ptr<absfac_ptn::AbstractProductA> productA1 = factory1->CreateProductA();
    std::unique_ptr<absfac_ptn::AbstractProductB> productB1 = factory1->CreateProductB();
    productA1->OperationA();
    productB1->OperationB();

    std::unique_ptr<absfac_ptn::AbstractFactory> factory2 = std::make_unique<absfac_ptn::ConcreteFactory2>();
    std::unique_ptr<absfac_ptn::AbstractProductA> productA2 = factory2->CreateProductA();
    std::unique_ptr<absfac_ptn::AbstractProductB> productB2 = factory2->CreateProductB();
    productA2->OperationA();
    productB2->OperationB();

    return 0;
}
