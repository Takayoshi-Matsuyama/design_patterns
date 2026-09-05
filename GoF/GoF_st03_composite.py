"""
Implementation of the Composite design pattern.

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


class NotSupportedError(Exception):
    """Exception raised when an unsupported operation is attempted."""

    ...  # No additional implementation needed for this exception class.


class Component(ABC):
    """Represents the component interface in the Composite design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def operation(self) -> str:
        """Performs an operation on the component.

        Returns:
            str: The result of the operation on the component.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def add(self, component: Component) -> None:
        """Adds a child component to the composite.

        Args:
            component (Component): The child component to add.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def remove(self, component: Component) -> None:
        """Removes a child component from the composite.

        Args:
            component (Component): The child component to remove.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def get_child(self, index: int) -> Component:
        """Retrieves a child component by its index.

        Args:
            index (int): The index of the child component to retrieve.

        Returns:
            Component: The child component at the specified index.
        """
        ...  # Should be implemented by concrete subclasses.


class Leaf(Component):
    """Represents a leaf node in the Composite design pattern."""

    def operation(self) -> str:
        """Performs an operation on the leaf component.

        Returns:
            str: The result of the operation on the leaf component.
        """
        return "Leaf operation"

    def add(self, component: Component) -> None:
        """Attempts to add a child component to the leaf node.

        Args:
            component (Component): The child component to add.

        Raises:
            NotSupportedError: Leaf nodes cannot add components.
        """
        raise NotSupportedError("Leaf nodes cannot add components")

    def remove(self, component: Component) -> None:
        """Attempts to remove a child component from the leaf node.

        Args:
            component (Component): The child component to remove.

        Raises:
            NotSupportedError: Leaf nodes cannot remove components.
        """
        raise NotSupportedError("Leaf nodes cannot remove components")

    def get_child(self, index: int) -> Component:
        """Retrieves a child component by its index.

        Args:
            index (int): The index of the child component to retrieve.

        Returns:
            Component: Always raises NotSupportedError because leaf does not have children.
        """
        raise NotSupportedError("Leaf nodes do not have children")


class Composite(Component):
    """Represents a composite node in the Composite design pattern."""

    def __init__(self) -> None:
        """Initializes a composite node."""
        self.children: list[Component] = []

    def operation(self) -> str:
        """Performs an operation on the composite node.

        Returns:
            str: The result of the operation on the composite node.
        """
        results = [child.operation() for child in self.children]
        return f"Composite operation: {', '.join(results)}"

    def add(self, component: Component) -> None:
        """Adds a child component to the composite node.

        Args:
            component (Component): The child component to add.
        """
        self.children.append(component)

    def remove(self, component: Component) -> None:
        """Removes a child component from the composite node.

        Args:
            component (Component): The child component to remove.
        """
        self.children.remove(component)

    def get_child(self, index: int) -> Component:
        """Retrieves a child component by its index.

        Args:
            index (int): The index of the child component to retrieve.

        Returns:
            Component: The child component at the specified index.
        """
        return self.children[index]


def main() -> None:
    """Demonstrates the Composite design pattern."""
    leaf1 = Leaf()
    leaf2 = Leaf()
    composite = Composite()
    composite.add(leaf1)
    composite.add(leaf2)

    print(composite.operation())


if __name__ == "__main__":
    main()
