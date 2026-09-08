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
    def visit_concrete_element_a(self, element_a: ConcreteElementA) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element_a (ConcreteElementA): The element to be visited.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def visit_concrete_element_b(self, element_b: ConcreteElementB) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element_b (ConcreteElementB): The element to be visited.
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

    def visit_concrete_element_a(self, element_a: ConcreteElementA) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element_a (ConcreteElementA): The element to be visited.
        """
        print(f"ConcreteVisitor #1: Visiting {element_a.__class__.__name__}")

    def visit_concrete_element_b(self, element_b: ConcreteElementB) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element_b (ConcreteElementB): The element to be visited.
        """
        print(f"ConcreteVisitor #1: Visiting {element_b.__class__.__name__}")


class ConcreteVisitor2(Visitor):
    """Represents a concrete implementation of the Visitor in the Visitor design pattern."""

    def visit_concrete_element_a(self, element_a: ConcreteElementA) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element_a (ConcreteElementA): The element to be visited.
        """
        print(f"ConcreteVisitor #2: Visiting {element_a.__class__.__name__}")

    def visit_concrete_element_b(self, element_b: ConcreteElementB) -> None:
        """Visits an element and performs an operation on it.

        Args:
            element_b (ConcreteElementB): The element to be visited.
        """
        print(f"ConcreteVisitor #2: Visiting {element_b.__class__.__name__}")


class ConcreteElementA(Element):
    """Represents a concrete implementation of the Element in the Visitor design pattern."""

    def accept(self, visitor: Visitor) -> None:
        """Accepts a visitor and allows it to perform an operation on this element.

        Args:
            visitor (Visitor): The visitor that will perform an operation on this element.
        """
        visitor.visit_concrete_element_a(self)


class ConcreteElementB(Element):
    """Represents a concrete implementation of the Element in the Visitor design pattern."""

    def accept(self, visitor: Visitor) -> None:
        """Accepts a visitor and allows it to perform an operation on this element.

        Args:
            visitor (Visitor): The visitor that will perform an operation on this element.
        """
        visitor.visit_concrete_element_b(self)


class ObjectStructure:
    """Represents the Object Structure in the Visitor design pattern.

    Note: The Object Structure can be a collection of elements that can be iterated over.
          It provides a way to access the elements and allows visitors to visit them.
    """

    def __init__(self) -> None:
        """Initializes the Object Structure with an empty list of elements."""
        self._elements: list[Element] = []

    def attach(self, element: Element) -> None:
        """Attaches an element to the Object Structure.

        Args:
            element (Element): The element to be attached.
        """
        self._elements.append(element)

    def detach(self, element: Element) -> None:
        """Detaches an element from the Object Structure.

        Args:
            element (Element): The element to be detached.
        """
        self._elements.remove(element)

    def accept(self, visitor: Visitor) -> None:
        """Accepts a visitor and allows it to visit all elements in the Object Structure.

        Args:
            visitor (Visitor): The visitor that will visit the elements.
        """
        for element in self._elements:
            element.accept(visitor)


def main() -> None:
    """Demonstrates the Visitor design pattern."""
    object_structure = ObjectStructure()
    object_structure.attach(ConcreteElementA())
    object_structure.attach(ConcreteElementB())

    visitor1 = ConcreteVisitor1()
    visitor2 = ConcreteVisitor2()
    object_structure.accept(visitor1)
    object_structure.accept(visitor2)


if __name__ == "__main__":
    main()
