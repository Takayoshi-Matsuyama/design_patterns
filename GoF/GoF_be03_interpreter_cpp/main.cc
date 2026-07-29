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

#include <iostream>

#include "context.h"
#include "non_terminal_expression.h"
#include "terminal_expression.h"

int main() {
  std::cout << "GoF Interpreter Pattern Example" << std::endl;

  interpreter_ptn::Context context(5);
  interpreter_ptn::TerminalExpression terminal_expression;
  terminal_expression.Interpret(context);
  std::cout << "TerminalExpression interpreted. Output value: "
            << context.GetOutput() << std::endl;

  interpreter_ptn::Context context2(10);
  interpreter_ptn::NonTerminalExpression non_terminal_expression(
    terminal_expression, terminal_expression);
  non_terminal_expression.Interpret(context2);
  std::cout << "NonTerminalExpression interpreted. Output value: "
            << context2.GetOutput() << std::endl;

  return 0;
}
