"""
Implementation of the Iterator design pattern.

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


class Iterator(ABC):
    """Represents the Iterator in the Iterator design pattern."""

    @abstractmethod
    def first(self) -> None:
        """Moves to the first element of the collection."""
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def next(self) -> None:
        """Moves to the next element of the collection."""
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def is_done(self) -> bool:
        """Checks if the iterator has reached the end of the collection.

        Returns:
            True if the iterator has reached the end of the collection,
            False otherwise.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def current_item(self) -> str:
        """Returns the current element in the collection.

        Returns:
            The current element in the collection.
        """
        ...  # Should be implemented by concrete subclasses.


class Aggregate(ABC):
    """Represents the Aggregate in the Iterator design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def create_iterator(self) -> Iterator:
        """Creates an iterator for the aggregate.

        Returns:
            Iterator: An iterator for the aggregate.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteAggregate(Aggregate):
    """Represents the Concrete Aggregate in the Iterator design pattern."""

    def __init__(self) -> None:
        """Initializes the Concrete Aggregate."""
        self._items: list[str] = ["A", "B", "C", "D", "E"]  # Demo data

    def create_iterator(self) -> Iterator:
        """Creates an iterator for the concrete aggregate.

        Returns:
            ConcreteIterator: An iterator for the concrete aggregate.
        """
        return ConcreteIterator(self)


class ConcreteIterator(Iterator):
    """Represents the Concrete Iterator in the Iterator design pattern."""

    def __init__(self, aggregate: Aggregate) -> None:
        """Initializes the Concrete Iterator.

        Args:
            aggregate (Aggregate): The aggregate to iterate over.
        """
        self._aggregate: Aggregate = aggregate
        self._current: int = 0

    def first(self) -> None:
        """Moves to the first element of the collection."""
        self._current = 0

    def next(self) -> None:
        """Moves to the next element of the collection."""
        self._current += 1

    def is_done(self) -> bool:
        """Checks if the iterator has reached the end of the collection.

        Returns:
            True if the iterator has reached the end of the collection,
            False otherwise.
        """
        return self._current >= len(self._aggregate._items)

    def current_item(self) -> str:
        """Returns the current element in the collection.

        Returns:
            The current element in the collection.

        Raises:
            StopIteration: If the iterator has reached the end of the collection.
        """
        if not self.is_done():
            return self._aggregate._items[self._current]
        else:
            raise StopIteration


def main() -> None:
    """Demonstrates the Iterator design pattern."""
    aggregate = ConcreteAggregate()
    iterator = aggregate.create_iterator()

    print("Iterating over the aggregate:")
    while not iterator.is_done():
        print(iterator.current_item())
        iterator.next()


if __name__ == "__main__":
    main()
