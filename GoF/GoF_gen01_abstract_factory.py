"""
Implementation of the Abstract Factory design pattern.

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


class AbstractProductA(ABC):
    """Abstract base class for ProductA."""

    @abstractmethod
    def operation_a(self) -> str:
        """Perform operation specific to ProductA."""
        pass  # Should be implemented by concrete subclasses.


class ProductA1(AbstractProductA):
    """Concrete implementation of ProductA1."""

    def operation_a(self) -> str:
        """Perform operation specific to ProductA1.

        Returns:
            str: Result of the operation.
        """
        return "ProductA1 operation"


class ProductA2(AbstractProductA):
    """Concrete implementation of ProductA2."""

    def operation_a(self) -> str:
        """Perform operation specific to ProductA2.

        Returns:
            str: Result of the operation.
        """
        return "ProductA2 operation"


class AbstractProductB(ABC):
    """Abstract base class for ProductB."""

    @abstractmethod
    def operation_b(self) -> str:
        """Perform operation specific to ProductB."""
        pass  # Should be implemented by concrete subclasses.


class ProductB1(AbstractProductB):
    """Concrete implementation of ProductB1."""

    def operation_b(self) -> str:
        """Perform operation specific to ProductB1.

        Returns:
            str: Result of the operation.
        """
        return "ProductB1 operation"


class ProductB2(AbstractProductB):
    """Concrete implementation of ProductB2."""

    def operation_b(self) -> str:
        """Perform operation specific to ProductB2.

        Returns:
            str: Result of the operation.
        """
        return "ProductB2 operation"


class AbstractFactory(ABC):
    """Abstract base class for factories."""

    @abstractmethod
    def create_product_a(self) -> AbstractProductA:
        """Creates an instance of ProductA."""
        pass  # Should be implemented by concrete subclasses.

    @abstractmethod
    def create_product_b(self) -> AbstractProductB:
        """Creates an instance of ProductB."""
        pass  # Should be implemented by concrete subclasses.


class ConcreteFactory1(AbstractFactory):
    """Concrete implementation of Factory1."""

    def create_product_a(self) -> AbstractProductA:
        """Create and return an instance of ProductA1.

        Returns:
            AbstractProductA: Instance of ProductA1.
        """
        return ProductA1()

    def create_product_b(self) -> AbstractProductB:
        """Create and return an instance of ProductB1.

        Returns:
            AbstractProductB: Instance of ProductB1.
        """
        return ProductB1()


class ConcreteFactory2(AbstractFactory):
    """Concrete implementation of Factory2."""

    def create_product_a(self) -> AbstractProductA:
        """Create and return an instance of ProductA2.

        Returns:
            AbstractProductA: Instance of ProductA2.
        """
        return ProductA2()

    def create_product_b(self) -> AbstractProductB:
        """Create and return an instance of ProductB2.

        Returns:
            AbstractProductB: Instance of ProductB2.
        """
        return ProductB2()


def main() -> None:
    """Demonstrate the usage of the abstract factory pattern."""
    factory1 = ConcreteFactory1()
    product_a1 = factory1.create_product_a()
    product_b1 = factory1.create_product_b()
    print(product_a1.operation_a())
    print(product_b1.operation_b())

    factory2 = ConcreteFactory2()
    product_a2 = factory2.create_product_a()
    product_b2 = factory2.create_product_b()
    print(product_a2.operation_a())
    print(product_b2.operation_b())


if __name__ == "__main__":
    """Entry point for the Abstract Factory pattern demonstration."""
    main()
