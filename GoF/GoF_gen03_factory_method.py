"""
Implementation of the Factory Method design pattern.

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


class Product(ABC):
    """Represents the abstract product interface.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def operation(self) -> str:
        """Performs an operation specific to the product."""
        ...  # Should be implemented by concrete subclasses.


class ConcreteProduct(Product):
    """Represents the concrete implementation of the Product interface."""

    def operation(self) -> str:
        """Performs an operation specific to the concrete product.

        Returns:
            str: The result of the operation.
        """
        return "Operation of ConcreteProduct"


class Creator(ABC):
    """Represents the abstract creator interface."""

    @abstractmethod
    def factory_method(self) -> Product:
        """Creates and returns a product instance."""
        ...  # Should be implemented by concrete subclasses.

    def some_operation(self) -> str:
        """Performs some operation using the product created by the factory method.

        Returns:
            str: The result of the operation using the product.
        """
        product = self.factory_method()
        return f"Creator: Working with {product.operation()}"


class ConcreteCreator(Creator):
    """Represents the concrete implementation of the Creator interface."""

    def factory_method(self) -> Product:
        """Creates and returns a concrete product instance.

        Returns:
            Product: The created concrete product instance.
        """
        return ConcreteProduct()


def main() -> None:
    """Demonstrates the usage of the Factory Method pattern."""
    creator = ConcreteCreator()
    result = creator.some_operation()
    print(result)


if __name__ == "__main__":
    main()
