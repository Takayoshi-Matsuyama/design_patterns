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

#include "concrete_element_a.h"
#include "concrete_element_b.h"
#include "concrete_visitor_1.h"
#include "concrete_visitor_2.h"

#include <iostream>
#include <list>

int main() {
    
    std::cout << "GoF Visitor Pattern Example" << std::endl;

    std::list<Element*> elements;
    elements.push_back(new ConcreteElementA());
    elements.push_back(new ConcreteElementB());

    ConcreteVisitor1 visitor1;
    ConcreteVisitor2 visitor2;

    for (Element* element : elements) {
        element->Accept(visitor1);
        element->Accept(visitor2);
    }

    return 0;
}
