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

#include "Composite.h"

void Composite::Operation() {
    std::cout << "Composite Operation" << std::endl;
    for (const auto& child : this->children) {
        child->Operation();
    }
}

void Composite::Add(std::shared_ptr<Component> component) {
    this->children.push_back(component);
}

void Composite::Remove(std::shared_ptr<Component> component) {
    this->children.erase(std::remove(this->children.begin(), this->children.end(), component), this->children.end());
}

std::shared_ptr<Component> Composite::GetChild(int index) {
    if (index < 0 || index >= static_cast<int>(this->children.size())) {
        return nullptr;
    }
    return this->children[index];
}
