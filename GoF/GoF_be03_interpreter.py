# Copyright 2026 Takayoshi Matsuyama
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


class Context:
    def __init__(self, input):
        self.input = input
        self.output = 0


class AbstractExpression:
    def __init__(self):
        raise NotImplementedError("You should implement this method in subclasses")

    def interpret(self, context):
        raise NotImplementedError("You should implement this method in subclasses")


class TerminalExpression(AbstractExpression):
    def __init__(self):
        pass

    def interpret(self, context):
        context.output += int(context.input)


class NonTerminalExpression(AbstractExpression):
    def __init__(self, expression1, expression2):
        self.expression1 = expression1
        self.expression2 = expression2

    def interpret(self, context):
        self.expression1.interpret(context)
        self.expression2.interpret(context)


if __name__ == "__main__":
    context = Context("5")
    terminal_expression = TerminalExpression()
    terminal_expression.interpret(context)
    print(f"Terminal Expression Output: {context.output}")

    context2 = Context("10")
    non_terminal_expression = NonTerminalExpression(
        terminal_expression, terminal_expression
    )
    non_terminal_expression.interpret(context2)
    print(f"Non-Terminal Expression Output: {context2.output}")
