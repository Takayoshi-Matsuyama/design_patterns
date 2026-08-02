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

#ifndef DESIGN_PTN_BE04_ITER_CONCRETE_ITERATOR_H
#define DESIGN_PTN_BE04_ITER_CONCRETE_ITERATOR_H

#include "aggregate.h"
#include "iterator.h"

namespace iter_ptn {

class ConcreteIterator : public Iterator {
 public:
  // Constructs a ConcreteIterator for the given aggregate.
  explicit ConcreteIterator(const Aggregate& aggregate);

  // Sets current to the first item.
  void First() override;

  // Advances current to the next item.
  void Next() override;

  // Returns true if the current position is at the end of the aggregate.
  bool IsDone() const override;

  // Returns the current item.
  std::string CurrentItem() const override;

 private:
  // Reference to the aggregate being iterated over.
  const Aggregate& aggregate_;

  // Current index in the aggregate.
  int current_index_;
};

} // namespace iter_ptn

#endif // DESIGN_PTN_BE04_ITER_CONCRETE_ITERATOR_H
