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

#ifndef NON_TERMINAL_EXPRESSION_H
#define NON_TERMINAL_EXPRESSION_H

#include "AbstractExpression.h"
#include "Context.h"

class NonTerminalExpression : public AbstractExpression {
    public:
        NonTerminalExpression(AbstractExpression& expression1, AbstractExpression& expression2)
            : _expression1(expression1), _expression2(expression2) {}
        void Interpret(Context& context) override {
            _expression1.Interpret(context);
            _expression2.Interpret(context);
        }
    private:
        AbstractExpression& _expression1;
        AbstractExpression& _expression2;
};

#endif // NON_TERMINAL_EXPRESSION_H
