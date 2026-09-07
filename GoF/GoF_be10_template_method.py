"""
Implementation of the Template Method design pattern.

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


class AbstractClass(ABC):
    """Represents the Abstract Class in the Template Method design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    def template_method(self) -> None:
        """Defines the skeleton of an algorithm, deferring some steps to subclasses."""
        self.primitive_operation1()
        self.primitive_operation2()

    @abstractmethod
    def primitive_operation1(self) -> None:
        """A primitive operation that must be implemented by subclasses."""
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def primitive_operation2(self) -> None:
        """A primitive operation that must be implemented by subclasses."""
        ...  # Should be implemented by concrete subclasses.


class ConcreteClass(AbstractClass):
    """Represents a concrete implementation of the Abstract Class in the Template Method design pattern."""

    def primitive_operation1(self) -> None:
        """The first primitive operation."""
        print("ConcreteClass: Implementing primitive_operation1")

    def primitive_operation2(self) -> None:
        """The second primitive operation."""
        print("ConcreteClass: Implementing primitive_operation2")


def main() -> None:
    """Demonstrates the Template Method design pattern."""
    concrete = ConcreteClass()
    concrete.template_method()


if __name__ == "__main__":
    main()
