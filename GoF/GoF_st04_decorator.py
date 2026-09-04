"""
Implementation of the Decorator design pattern.

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


class Component(ABC):
    """Represents the component interface in the Decorator design pattern."""

    @abstractmethod
    def operation(self) -> None:
        """Performs an operation on the component."""
        ...  # Should be implemented by concrete subclasses.


class ConcreteComponent(Component):
    """Represents a concrete component in the Decorator design pattern."""

    def operation(self) -> None:
        """Performs an operation on the concrete component."""
        print("ConcreteComponent: Executed.")


class Decorator(Component):
    """Represents the base decorator in the Decorator design pattern."""

    def __init__(self, component: Component) -> None:
        """Initializes the base decorator with a component.

        Args:
            component (Component): The component to be decorated.
        """
        self._component = component

    def operation(self) -> None:
        """Performs an operation on the decorated component."""
        self._component.operation()


class ConcreteDecoratorA(Decorator):
    """Represents a concrete decorator A in the Decorator design pattern."""

    def __init__(self, component: Component) -> None:
        """Initializes ConcreteDecoratorA with a component and added state.

        Args:
            component (Component): The component to be decorated.
        """
        super().__init__(component)
        self.added_state = "Added state"

    def operation(self) -> None:
        """Performs an operation on the concrete decorator A."""
        super().operation()
        print(f"ConcreteDecoratorA: {self.added_state}")


class ConcreteDecoratorB(Decorator):
    """Represents a concrete decorator B in the Decorator design pattern."""

    def operation(self) -> None:
        """Performs an operation on the concrete decorator B."""
        super().operation()
        self.added_behavior()

    def added_behavior(self) -> None:
        """Performs the added behavior specific to ConcreteDecoratorB."""
        print("ConcreteDecoratorB: Added behavior.")


def main() -> None:
    """Demonstrates the usage of the Decorator design pattern."""
    component = ConcreteComponent()
    print("Original component operation:")
    component.operation()

    decorator_a = ConcreteDecoratorA(component)
    print("\nAfter applying ConcreteDecoratorA:")
    decorator_a.operation()

    decorator_b = ConcreteDecoratorB(decorator_a)
    print("\nAfter applying ConcreteDecoratorB on top of ConcreteDecoratorA:")
    decorator_b.operation()


if __name__ == "__main__":
    main()
