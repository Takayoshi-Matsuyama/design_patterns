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

#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"

ConcreteAggregate::ConcreteAggregate() {
    this->_items = std::vector<std::string>{"A", "B", "C", "D", "E"};
}

std::unique_ptr<Iterator> ConcreteAggregate::CreateIterator() const {
    return std::make_unique<ConcreteIterator>(*this);
}

int ConcreteAggregate::GetSize() const {
    return static_cast<int>(this->_items.size());
}

std::string ConcreteAggregate::GetItem(int index) const {
    if (index < 0 || index >= this->GetSize()) {
        return "";
    }
    return this->_items[index];
}
