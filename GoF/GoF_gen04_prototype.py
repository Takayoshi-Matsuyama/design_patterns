"""
Implementation of the Prototype design pattern.

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

import copy
from abc import ABC, abstractmethod
from typing import Self


class Prototype(ABC):
    """Represents the abstract prototype interface."""

    @abstractmethod
    def clone(self) -> Self:
        """Creates and returns a copy of the current object."""
        pass  # Should be implemented by concrete subclasses.


class ConcretePrototype(Prototype):
    """Represents the concrete implementation of the Prototype interface."""

    def __init__(self) -> None:
        """Initializes a new instance of the ConcretePrototype class."""
        self._data = None

    def set_data(self, data: list) -> None:
        """Sets the data for the concrete prototype.

        Args:
            data: The data to be set for the concrete prototype.
        """
        self._data = data

    def clone(self) -> Self:
        """Creates and returns a copy of the current concrete prototype.

        Returns:
            Self: A deep copy of the current concrete prototype.
        """
        return copy.deepcopy(self)


def main():
    """Demonstrates the usage of the Prototype design pattern."""
    prototype = ConcretePrototype()
    prototype.set_data([[0, 1], [2, 3]])

    clone = prototype.clone()
    print(f"Cloned object type: {type(clone).__name__}")

    print(f"Original object data: {prototype._data}")
    print(f"Cloned object data: {clone._data}")

    # Confirm that the cloned object is a deep copy
    # and independent of the original.
    clone._data[0][0] = 99
    print(f"Modified cloned object data: {clone._data}")
    print(f"Original object data after modifying clone: {prototype._data}")


if __name__ == "__main__":
    main()
