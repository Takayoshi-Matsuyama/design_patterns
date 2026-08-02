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

#include "concrete_iterator.h"

namespace iter_ptn {

ConcreteIterator::ConcreteIterator(const Aggregate& aggregate)
  : aggregate_(aggregate), current_index_(0) {}

void ConcreteIterator::First() {
  current_index_ = 0;
}

void ConcreteIterator::Next() {
  ++current_index_;
}

bool ConcreteIterator::IsDone() const {
  return current_index_ >= aggregate_.GetSize();
}

std::string ConcreteIterator::CurrentItem() const {
  if (this->IsDone()) {
      return "";
  }
  return aggregate_.GetItem(current_index_);
}

} // namespace iter_ptn
