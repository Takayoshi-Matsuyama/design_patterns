"""
Implementation of the State design pattern.

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


class State(ABC):
    """Represents the State in the State design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def handle(self) -> None:
        """Handles the request based on the current state."""
        ...  # Should be implemented by concrete subclasses.


class ConcreteStateA(State):
    """Represents a concrete implementation of the State in the State design pattern."""

    def handle(self) -> None:
        """Handles the request in State A."""
        print("ConcreteStateA: Handling request in State A.")


class ConcreteStateB(State):
    """Represents a concrete implementation of the State in the State design pattern."""

    def handle(self) -> None:
        """Handles the request in State B."""
        print("ConcreteStateB: Handling request in State B.")


class Context:
    """Represents the Context in the State design pattern."""

    def __init__(self):
        """Initializes the Context with no state."""
        self._state: State | None = None

    def set_state(self, state: State) -> None:
        """Sets the current state of the Context.

        Args:
            state (State): The new state of the Context.
        """
        self._state = state

    def request(self) -> None:
        """Handles the request by delegating to the current state."""
        if self._state:
            self._state.handle()
        else:
            print("Context: No state set to handle the request.")


def main() -> None:
    """Demonstrates the State design pattern."""
    context = Context()

    state_a = ConcreteStateA()
    state_b = ConcreteStateB()

    context.set_state(state_a)
    context.request()

    context.set_state(state_b)
    context.request()


if __name__ == "__main__":
    main()
