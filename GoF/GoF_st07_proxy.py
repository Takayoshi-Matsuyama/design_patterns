"""
Implementation of the Proxy design pattern.

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


class Subject(ABC):
    """Represents the Subject in the Proxy design pattern."""

    @abstractmethod
    def request(self) -> None:
        """Requests the subject to perform an action."""
        ...  # Should be implemented by concrete subclasses.


class RealSubject(Subject):
    """Represents the RealSubject in the Proxy design pattern."""

    def __init__(self) -> None:
        """Initializes the RealSubject."""
        self.is_ready = False

    def request(self) -> None:
        """Requests the RealSubject to perform an action."""
        print("RealSubject: Handling request.")


class Proxy(Subject):
    """Represents the Proxy in the Proxy design pattern."""

    def __init__(self) -> None:
        """Initializes the Proxy."""
        self._real_subject = RealSubject()

    def request(self) -> None:
        """Requests the Proxy to perform an action."""
        if self._real_subject.is_ready:
            print("Proxy: Forwarding request to RealSubject.")
            self._real_subject.request()
        else:
            print("Proxy: RealSubject is not ready.")


def main() -> None:
    """Demonstrates the Proxy design pattern."""
    proxy = Proxy()
    proxy.request()


if __name__ == "__main__":
    main()
