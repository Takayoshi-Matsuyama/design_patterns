"""
Implementation of the Builder design pattern.

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


class Product:
    """Represents the product to be built."""

    def __init__(self, name: str) -> None:
        """Initializes the product with a name.

        Args:
            name (str): The name of the product.
        """
        self.name = name


class Builder(ABC):
    """Represents the abstract builder interface."""

    @abstractmethod
    def build_part(self) -> Self:
        """Builds a part of the product.

        Returns:
            Self: The builder instance itself.
        """
        ...  # Should be implemented by concrete subclasses.
        return self  # Return the builder instance itself for method chaining.

    @abstractmethod
    def get_result(self) -> Product:
        """Returns the constructed product."""
        ...  # Should be implemented by concrete subclasses.


class ConcreteBuilder(Builder):
    """Represents the concrete implementation of the Builder interface."""

    def __init__(self) -> None:
        """Initializes the concrete builder."""
        self.reset()

    def reset(self) -> None:
        """Resets the builder to its initial state."""
        self.product = Product("Default")

    def build_part(self) -> Self:
        """Builds a part of the product by creating an example product.

        Returns:
            Self: The builder instance itself.
        """
        self.product = Product("Example Product")
        return self  # Return the builder instance itself for method chaining.

    def get_result(self) -> Product:
        """Returns the constructed product.

        Returns:
            Product: The constructed product.
        """
        return self.product


class Director:
    """Represents the director that constructs the product using the builder."""

    def __init__(self, builder: Builder) -> None:
        """Initializes the director with a builder.

        Args:
            builder (Builder): The builder used by the director.
        """
        self._builder = builder

    def construct(self) -> None:
        """Constructs the product using the builder."""
        self._builder.build_part()


def main() -> None:
    """Demonstrates the usage of the builder pattern."""
    builder = ConcreteBuilder()
    director = Director(builder)
    director.construct()
    product = builder.get_result()
    builder.reset()
    print(f"Product created: {product.name}")


if __name__ == "__main__":
    main()
