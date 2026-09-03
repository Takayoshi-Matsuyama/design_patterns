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

from abc import ABC, abstractmethod
from typing import Self


class NotSupportedError(Exception):
    """Exception raised when an unsupported operation is attempted."""

    ...  # No additional implementation needed for this exception class.


class Component(ABC):
    """Represents the component interface in the Composite design pattern."""

    @abstractmethod
    def operation(self) -> str:
        """Performs an operation on the component.

        Returns:
            str: The result of the operation on the component.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def add(self, component: Self) -> None:
        """Adds a child component to the composite.

        Args:
            component (Self): The child component to add.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def remove(self, component: Self) -> None:
        """Removes a child component from the composite.

        Args:
            component (Self): The child component to remove.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def get_child(self, index: int) -> Self:
        """Retrieves a child component by its index.

        Args:
            index (int): The index of the child component to retrieve.

        Returns:
            Self: The child component at the specified index.
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

    def get_child(self, index: int) -> None:
        """Retrieves a child component by its index.

        Args:
            index (int): The index of the child component to retrieve.

        Returns:
            None: Always returns None. Because leaf does not have children.
        """
        return None


class Composite(Component):
    """Represents a composite node in the Composite design pattern."""

    def __init__(self):
        self.children = []

    def operation(self):
        results = []
        for child in self.children:
            results.append(child.operation())
        return f"Composite operation: {', '.join(results)}"

    def add(self, component):
        self.children.append(component)

    def remove(self, component):
        self.children.remove(component)

    def get_child(self, index):
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
