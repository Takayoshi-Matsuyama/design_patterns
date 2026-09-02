"""
Implementation of the Adapter design pattern.

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


class Target(ABC):
    """Target interface that defines the expected interface for the client."""

    @abstractmethod
    def request(self) -> str:
        """Requests the target operation.

        Returns:
            str: The result of the target request.
        """
        ...  # Should be implemented by concrete subclasses.


class Adaptee:
    """Adaptee class that has a specific interface incompatible with the Target."""

    def specific_request(self) -> str:
        """Defines the specific request method of the adaptee.

        Returns:
            str: The result of the specific request.
        """
        return "Adaptee: The specific behavior of the adaptee."


class Adapter(Target):
    """Adapter class that makes the Adaptee's interface compatible with the Target."""

    def __init__(self, adaptee: Adaptee) -> None:
        """Initializes the Adapter with an instance of the Adaptee.

        Args:
            adaptee (Adaptee): The adaptee instance to be adapted.
        """
        self.adaptee = adaptee

    def request(self) -> str:
        """Requests the adapter operation.

        Returns:
            str: The processed response from the adaptee.
        """
        adaptee_response = self.adaptee.specific_request()
        processed_response = adaptee_response.upper()
        return f"Adapter: {processed_response}"


def main() -> None:
    """Demonstrates the usage of the Adapter design pattern."""
    adaptee = Adaptee()
    print("Adaptee:", adaptee.specific_request())

    adapter = Adapter(adaptee)
    print(adapter.request())


if __name__ == "__main__":
    main()
