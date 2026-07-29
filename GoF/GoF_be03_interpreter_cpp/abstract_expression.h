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

#ifndef DESIGN_PTN_BE03_INTERPRETER_ABSTRACT_EXPRESSION_H_
#define DESIGN_PTN_BE03_INTERPRETER_ABSTRACT_EXPRESSION_H_

#include "context.h"

namespace interpreter_ptn {

// Represents the abstract expression in the Interpreter pattern.
class AbstractExpression {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~AbstractExpression() = default;

  // Interprets the expression in the given context.
  virtual void Interpret(Context& context) = 0;
};

} // namespace interpreter_ptn

#endif // DESIGN_PTN_BE03_INTERPRETER_ABSTRACT_EXPRESSION_H_
