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

#ifndef DESIGN_PTN_BE03_INTERPRETER_NON_TERMINAL_EXPRESSION_H_
#define DESIGN_PTN_BE03_INTERPRETER_NON_TERMINAL_EXPRESSION_H_

#include "abstract_expression.h"
#include "context.h"

namespace interpreter_ptn {

// Represents a non-terminal expression in the Interpreter pattern.
class NonTerminalExpression : public AbstractExpression {
 public:
  // Constructs a NonTerminalExpression with two sub-expressions.
  NonTerminalExpression(AbstractExpression* expression1,
                        AbstractExpression* expression2)
    : expression1_(expression1), expression2_(expression2) {}

  // Interprets the non-terminal expression
  // by interpreting its sub-expressions in the given context.
  void Interpret(Context& context) override {
    expression1_->Interpret(context);
    expression2_->Interpret(context);
  }

 private:
  // Pointers to the two sub-expressions of this non-terminal expression.
  // The lifetime of the expressions must be managed outside of this class.
  AbstractExpression* expression1_;
  AbstractExpression* expression2_;
};

} // namespace interpreter_ptn

#endif // DESIGN_PTN_BE03_INTERPRETER_NON_TERMINAL_EXPRESSION_H_
