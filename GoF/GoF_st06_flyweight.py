"""
Implementation of the Flyweight design pattern.

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


class Flyweight(ABC):
    """Represents the Flyweight in the Flyweight design pattern."""

    @abstractmethod
    def operation(self, extrinsic_state: int) -> None:
        """Performs an operation using the extrinsic state.

        Args:
            extrinsic_state: The extrinsic state for the operation.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteFlyweight(Flyweight):
    """Represents the Concrete Flyweight in the Flyweight design pattern."""

    def __init__(self, intrinsic_state: int) -> None:
        """Initializes the Concrete Flyweight.

        Args:
            intrinsic_state: The intrinsic state for the flyweight.
        """
        self.intrinsic_state = intrinsic_state

    def operation(self, extrinsic_state: int) -> None:
        """Performs an operation using the extrinsic state.

        Args:
            extrinsic_state: The extrinsic state for the operation.
        """
        result = self.intrinsic_state + extrinsic_state
        print(f"ConcreteFlyweight: {result}")


class UnsharedConcreteFlyweight(Flyweight):
    """Represents the Unshared Concrete Flyweight in the Flyweight design pattern."""

    def __init__(self, intrinsic_state: int) -> None:
        """Initializes the Unshared Concrete Flyweight.

        Args:
            intrinsic_state: The intrinsic state for the unshared flyweight.
        """
        self.intrinsic_state = intrinsic_state

    def operation(self, extrinsic_state: int) -> None:
        """Performs an operation using the extrinsic state.

        Args:
            extrinsic_state: The extrinsic state for the operation.
        """
        result = self.intrinsic_state + extrinsic_state
        print(f"UnsharedConcreteFlyweight: {result}")


class FlyweightFactory:
    """Represents the Flyweight Factory in the Flyweight design pattern."""

    def __init__(self) -> None:
        """Initializes the Flyweight Factory."""
        self.flyweights = {}

    def get_flyweight(self, key: int, default_intrinsic_state: int):
        if key not in self.flyweights:
            self.flyweights[key] = ConcreteFlyweight(default_intrinsic_state)
        return self.flyweights[key]

    def get_unshared_flyweight(self, default_intrinsic_state: int):
        return UnsharedConcreteFlyweight(default_intrinsic_state)


def main():
    """Demonstrates the Flyweight design pattern."""
    factory = FlyweightFactory()

    flyweight1 = factory.get_flyweight(1, 2)
    flyweight2a = factory.get_flyweight(2, 3)
    flyweight2b = factory.get_flyweight(2, 99)
    unshared_flyweight = factory.get_unshared_flyweight(4)

    flyweight1.operation(10)
    flyweight2a.operation(20)
    flyweight2b.operation(30)
    unshared_flyweight.operation(40)

    print(
        f"Flyweight1 and Flyweight2a are the same instance: {flyweight1 is flyweight2a=}"
    )
    print(
        f"Flyweight2a and Flyweight2b are the same instance: {flyweight2a is flyweight2b=}"
    )
    print(
        f"Unshared Flyweight is a different instance: {unshared_flyweight is not flyweight1=}"
    )


if __name__ == "__main__":
    main()
