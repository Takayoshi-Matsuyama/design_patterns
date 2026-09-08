"""
Implementation of the Visitor design pattern.

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

from __future__ import annotations
from abc import ABC, abstractmethod


class Visitor(ABC):
    """Represents the Visitor in the Visitor design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def visit(self, element: Element) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element (Element): The element to be visited.
        """
        ...  # Should be implemented by concrete subclasses.


class Element(ABC):
    """Represents the Element in the Visitor design pattern."""

    @abstractmethod
    def accept(self, visitor: Visitor) -> None:
        """Accepts a visitor and allows it to perform an operation on this element.

        Args:
            visitor (Visitor): The visitor that will perform an operation on this element.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteVisitor1(Visitor):
    """Represents a concrete implementation of the Visitor in the Visitor design pattern."""

    def visit(self, element: Element) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element (Element): The element to be visited.
        """
        print(f"ConcreteVisitor #1: Visiting {element.__class__.__name__}")


class ConcreteVisitor2(Visitor):
    """Represents a concrete implementation of the Visitor in the Visitor design pattern."""

    def visit(self, element: Element) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element (Element): The element to be visited.
        """
        print(f"ConcreteVisitor #2: Visiting {element.__class__.__name__}")


class ConcreteElementA(Element):
    """Represents a concrete implementation of the Element in the Visitor design pattern."""

    def accept(self, visitor: Visitor) -> None:
        """Accepts a visitor and allows it to perform an operation on this element.

        Args:
            visitor (Visitor): The visitor that will perform an operation on this element.
        """
        visitor.visit(self)


class ConcreteElementB(Element):
    """Represents a concrete implementation of the Element in the Visitor design pattern."""

    def accept(self, visitor: Visitor) -> None:
        """Accepts a visitor and allows it to perform an operation on this element.

        Args:
            visitor (Visitor): The visitor that will perform an operation on this element.
        """
        visitor.visit(self)


def main() -> None:
    """Demonstrates the Visitor design pattern."""
    elements = [ConcreteElementA(), ConcreteElementB()]
    visitor1 = ConcreteVisitor1()
    visitor2 = ConcreteVisitor2()

    for element in elements:
        element.accept(visitor1)
        element.accept(visitor2)


if __name__ == "__main__":
    main()
