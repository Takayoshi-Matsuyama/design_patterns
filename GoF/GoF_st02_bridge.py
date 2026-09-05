"""
Implementation of the Bridge design pattern.

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


class Implementor(ABC):
    """Represents the implementor interface in the Bridge design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def operation_impl(self) -> str:
        """Performs the implementation-specific operation.

        Returns:
            str: The result of the implementation-specific operation.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteImplementorA(Implementor):
    """Represents the concrete implementation A of the Implementor."""

    def operation_impl(self) -> str:
        """Performs the implementation-specific operation for ConcreteImplementorA.

        Returns:
            str: The result of the implementation-specific operation.
        """
        return "Result A"


class ConcreteImplementorB(Implementor):
    """Represents the concrete implementation B of the Implementor."""

    def operation_impl(self) -> str:
        """Performs the implementation-specific operation for ConcreteImplementorB.

        Returns:
            str: The result of the implementation-specific operation.
        """
        return "Result B"


class Abstraction(ABC):
    """Represents the abstraction class in the Bridge design pattern."""

    def __init__(self, implementor: Implementor) -> None:
        """Initializes the abstraction with the given implementor.

        Args:
            implementor (Implementor): The implementor instance to be used by the abstraction.
        """
        self._implementor = implementor

    @abstractmethod
    def operation(self) -> str:
        """Performs an operation using the implementor.

        Returns:
            str: The result of the operation.
        """
        ...  # Should be implemented by concrete subclasses.


class RefinedAbstraction(Abstraction):
    """Represents the refined abstraction class in the Bridge design pattern."""

    def operation(self) -> str:
        """Performs an operation using the implementor.

        Returns:
            str: The result of the operation.
        """
        return f"Refined: {self._implementor.operation_impl()}"


def main() -> None:
    """Demonstrates the Bridge design pattern."""
    abstraction_a = RefinedAbstraction(ConcreteImplementorA())
    print(abstraction_a.operation())

    abstraction_b = RefinedAbstraction(ConcreteImplementorB())
    print(abstraction_b.operation())


if __name__ == "__main__":
    main()
