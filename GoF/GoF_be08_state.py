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

from __future__ import annotations
from abc import ABC, abstractmethod


class State(ABC):
    """Represents the State in the State design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def handle(self, context: Context) -> None:
        """Handles the request based on the current state.

        Args:
            context (Context): The context that holds the current state.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteStateA(State):
    """Represents a concrete implementation of the State in the State design pattern."""

    def handle(self, context: Context) -> None:
        """Handles the request in State A.

        Args:
            context (Context): The context that holds the current state.
        """
        print("ConcreteStateA: Handling request in State A.")
        context.set_state(
            ConcreteStateB()
        )  # Transition to State B after handling the request.


class ConcreteStateB(State):
    """Represents a concrete implementation of the State in the State design pattern."""

    def handle(self, context: Context) -> None:
        """Handles the request in State B.

        Args:
            context (Context): The context that holds the current state.
        """
        print("ConcreteStateB: Handling request in State B.")
        context.set_state(
            ConcreteStateA()
        )  # Transition to State A after handling the request.


class Context:
    """Represents the Context in the State design pattern."""

    def __init__(self, state: State) -> None:
        """Initializes the Context.

        Args:
            state (State): The initial state of the Context.
        """
        self._state: State = state

    def set_state(self, state: State) -> None:
        """Sets the current state of the Context.

        Args:
            state (State): The new state of the Context.
        """
        self._state = state

    def request(self) -> None:
        """Handles the request by delegating to the current state."""
        if self._state:
            self._state.handle(self)
        else:
            print("Context: No state set to handle the request.")


def main() -> None:
    """Demonstrates the State design pattern."""
    context = Context(ConcreteStateA())
    context.request()  # Output: "ConcreteStateA: Handling request in State A."
    context.request()  # Output: "ConcreteStateB: Handling request in State B."
    context.request()  # Output: "ConcreteStateA: Handling request in State A."
    context.request()  # Output: "ConcreteStateB: Handling request in State B."


if __name__ == "__main__":
    main()
