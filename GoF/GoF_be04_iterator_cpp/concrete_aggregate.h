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

#ifndef DESIGN_PTN_BE04_ITER_CONCRETE_AGGREGATE_H
#define DESIGN_PTN_BE04_ITER_CONCRETE_AGGREGATE_H

#include <string>
#include <vector>
#include <memory>

#include "aggregate.h"

namespace iter_ptn {

// Represents a concrete implementation of an aggregate object.
class ConcreteAggregate : public Aggregate {
 public:
  // Constructs a ConcreteAggregate with a predefined set of items.
  ConcreteAggregate();

  // Destroys the ConcreteAggregate.
  ~ConcreteAggregate() override;

  // Creates an iterator for the aggregate.
  std::unique_ptr<Iterator> CreateIterator() const override;

  // Returns the number of items in the aggregate.
  int GetSize() const override;

  // Returns the item at the specified index in the aggregate.
  std::string GetItem(int index) const override;

 private:
  // Stores the items in the aggregate.
  std::vector<std::string> items_;
};

} // namespace iter_ptn

#endif // DESIGN_PTN_BE04_ITER_CONCRETE_AGGREGATE_H
