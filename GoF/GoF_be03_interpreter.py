"""
Implementation of the Interpreter design pattern.

Copyright 2026 Takayoshi Matsuyama

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

from abc import ABC, abstractmethod


class Context:
    """Represents the Context in the Interpreter design pattern."""

    def __init__(self, input: str) -> None:
        """Initializes the Context.

        Args:
            input (str): The input string for interpretation.
        """
        self.input: str = input
        self.output: int = 0


class AbstractExpression(ABC):
    """Represents the Abstract Expression in the Interpreter design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def interpret(self, context: Context) -> None:
        """Interprets the context."""
        ...  # Should be implemented by concrete subclasses.


class TerminalExpression(AbstractExpression):
    """Represents the Terminal Expression in the Interpreter design pattern."""

    def interpret(self, context: Context) -> None:
        """Interprets the context for the terminal expression."""
        context.output += int(context.input)


class NonTerminalExpression(AbstractExpression):
    """Represents the Non-Terminal Expression in the Interpreter design pattern."""

    def __init__(
        self, expression1: AbstractExpression, expression2: AbstractExpression
    ) -> None:
        """Initializes the Non-Terminal Expression.

        Args:
            expression1 (AbstractExpression): The first sub-expression.
            expression2 (AbstractExpression): The second sub-expression.
        """
        self.expression1 = expression1
        self.expression2 = expression2

    def interpret(self, context: Context) -> None:
        """Interprets the context for the non-terminal expression."""
        self.expression1.interpret(context)
        self.expression2.interpret(context)


def main() -> None:
    """Demonstrates the Interpreter design pattern."""
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


if __name__ == "__main__":
    main()
