"""
Implementation of the Command design pattern.

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


class Receiver:
    """Represents the Receiver in the Command design pattern."""

    def action(self) -> None:
        """Performs the action."""
        print("Receiver: Performing the action.")


class Command(ABC):
    """Represents the Command in the Command design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def execute(self) -> None:
        """Executes the command."""
        ...  # Should be implemented by concrete subclasses.


class ConcreteCommand(Command):
    """Represents a concrete command in the Command design pattern."""

    def __init__(self, receiver: Receiver) -> None:
        """Initializes the ConcreteCommand.

        Args:
            receiver (Receiver): The receiver of the command.
        """
        self._receiver = receiver

    def execute(self) -> None:
        """Executes the command."""
        self._receiver.action()


class Invoker:
    """Represents the Invoker in the Command design pattern."""

    def __init__(self) -> None:
        """Initializes the Invoker."""
        self._command: Command | None = None

    def set_command(self, command: Command) -> None:
        """Sets the command to be executed by the Invoker.

        Args:
            command (Command): The command to be executed.
        """
        self._command = command

    def execute_command(self) -> None:
        """Executes the command if it is set."""
        if self._command:
            self._command.execute()


def main() -> None:
    """Demonstrates the Command design pattern."""
    receiver = Receiver()
    command = ConcreteCommand(receiver)

    invoker = Invoker()
    invoker.set_command(command)
    invoker.execute_command()


if __name__ == "__main__":
    main()
