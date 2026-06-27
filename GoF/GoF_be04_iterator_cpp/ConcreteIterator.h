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

#ifndef CONCRETE_ITERATOR_H
#define CONCRETE_ITERATOR_H

#include "Iterator.h"
#include "Aggregate.h"

class ConcreteIterator : public Iterator {
    public:
        explicit ConcreteIterator(const Aggregate& aggregate);
        void First() override;
        void Next() override;
        bool IsDone() const override;
        std::string CurrentItem() const override;

    private:
        const Aggregate& _aggregate;
        int _currentIndex;
};

#endif // CONCRETE_ITERATOR_H
