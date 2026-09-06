"""
Implementation of the Memento design pattern.

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


class Memento:
    """Represents the Memento in the Memento design pattern."""

    def __init__(self, state: str) -> None:
        """Initializes the Memento with the given state.

        Args:
            state (str): The state to be stored in the Memento.
        """
        self._state: str = state

    def get_state(self) -> str:
        """Returns the state stored in the Memento.

        Returns:
            str: The state stored in the Memento.
        """
        return self._state


class Originator:
    """Represents the Originator in the Memento design pattern."""

    def __init__(self) -> None:
        """Initializes the Originator with no state."""
        self._state: str = ""  # Empty string

    def set_state(self, state: str) -> None:
        """Sets the state of the Originator.

        Args:
            state (str): The new state of the Originator.
        """
        self._state = state

    def get_state(self) -> str:
        """Returns the current state of the Originator.

        Returns:
            str: The current state of the Originator.
        """
        return self._state

    def create_memento(self) -> Memento:
        """Creates a Memento containing the current state of the Originator.

        Returns:
            Memento: A Memento containing the current state of the Originator.
        """
        return Memento(self._state)

    def set_memento(self, memento: Memento) -> None:
        """Restores the Originator's state from the given Memento.

        Args:
            memento (Memento): The Memento from which to restore the state.
        """
        self._state = memento.get_state()


class Caretaker:
    """Represents the Caretaker in the Memento design pattern."""

    def __init__(self) -> None:
        """Initializes the Caretaker with an empty list of Mementos."""
        self._mementos: list[Memento] = []

    def add_memento(self, memento: Memento) -> None:
        """Adds a Memento to the Caretaker's list.

        Args:
            memento (Memento): The Memento to be added to the Caretaker's list.
        """
        self._mementos.append(memento)

    def get_memento(self, index: int) -> Memento:
        """Retrieves a Memento from the Caretaker's list by index.

        Args:
            index (int): The index of the Memento to retrieve.

        Returns:
            Memento: The Memento at the specified index.
        """
        return self._mementos[index]


def main() -> None:
    """Demonstrates the Memento design pattern."""
    originator = Originator()
    caretaker = Caretaker()

    originator.set_state("State 1")
    caretaker.add_memento(originator.create_memento())

    originator.set_state("State 2")
    caretaker.add_memento(originator.create_memento())

    originator.set_state("State 3")
    caretaker.add_memento(originator.create_memento())

    print(f"Current State: {originator.get_state()}")

    originator.set_memento(caretaker.get_memento(0))
    print(f"Restored State: {originator.get_state()}")

    originator.set_memento(caretaker.get_memento(1))
    print(f"Restored State: {originator.get_state()}")

    originator.set_memento(caretaker.get_memento(2))
    print(f"Restored State: {originator.get_state()}")


if __name__ == "__main__":
    main()
