"""
Implementation of the Strategy design pattern.

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


class Strategy(ABC):
    """Represents the Strategy in the Strategy design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def execute_algorithm(self, a: int, b: int) -> int:
        """Executes the algorithm defined by the strategy.

        Args:
            a (int): The first operand.
            b (int): The second operand.

        Returns:
            int: The result of the algorithm.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteStrategyA(Strategy):
    """Represents a concrete implementation of the Strategy in the Strategy design pattern."""

    def execute_algorithm(self, a: int, b: int) -> int:
        """Executes the algorithm defined by Strategy A (addition).

        Args:
            a (int): The first operand.
            b (int): The second operand.

        Returns:
            int: The result of the addition.
        """
        return a + b


class ConcreteStrategyB(Strategy):
    """Represents a concrete implementation of the Strategy in the Strategy design pattern."""

    def execute_algorithm(self, a: int, b: int) -> int:
        """Executes the algorithm defined by Strategy B (subtraction).

        Args:
            a (int): The first operand.
            b (int): The second operand.

        Returns:
            int: The result of the subtraction.
        """
        return a - b


class ConcreteStrategyC(Strategy):
    """Represents a concrete implementation of the Strategy in the Strategy design pattern."""

    def execute_algorithm(self, a: int, b: int) -> int:
        """Executes the algorithm defined by Strategy C (multiplication).

        Args:
            a (int): The first operand.
            b (int): The second operand.

        Returns:
            int: The result of the multiplication.
        """
        return a * b


class Context:
    """Represents the Context in the Strategy design pattern."""

    def __init__(self, strategy: Strategy) -> None:
        """Initializes the Context with a strategy.

        Args:
            strategy (Strategy): The initial strategy to be used by the context.
        """
        self._strategy: Strategy = strategy

    def set_strategy(self, strategy: Strategy) -> None:
        """Sets a new strategy for the context.

        Args:
            strategy (Strategy): The new strategy to be used by the context.
        """
        self._strategy = strategy

    def execute_strategy(self, a: int, b: int) -> int:
        """Executes the current strategy with the given operands.

        Args:
            a (int): The first operand.
            b (int): The second operand.

        Returns:
            int: The result of the strategy's algorithm.
        """
        return self._strategy.execute_algorithm(a, b)


def main() -> None:
    """Demonstrates the Strategy design pattern."""
    a = 5
    b = 3
    print(f"Operands: a = {a}, b = {b}")

    context = Context(ConcreteStrategyA())
    result = context.execute_strategy(a, b)
    print(f"Addition Result = {result}")

    context.set_strategy(ConcreteStrategyB())
    result = context.execute_strategy(a, b)
    print(f"Subtraction Result = {result}")

    context.set_strategy(ConcreteStrategyC())
    result = context.execute_strategy(a, b)
    print(f"Multiplication Result = {result}")


if __name__ == "__main__":
    main()
