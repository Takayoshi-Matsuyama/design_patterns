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
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime
from time import sleep


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
        print(f"{datetime.now().strftime('%H:%M:%S')} RealSubject: Initializing.")
        self.is_ready = False

        # Executes time-consuming preparation in a separate thread.
        executor = ThreadPoolExecutor(max_workers=1)
        executor.submit(self.prepare)

    def prepare(self) -> None:
        """Prepares the RealSubject to handle requests."""
        sleep(2)  # Simulate preparation time.
        self.is_ready = True

    def request(self) -> None:
        """Requests the RealSubject to perform an action."""
        print(f"{datetime.now().strftime('%H:%M:%S')} RealSubject: Handling request.")


class Proxy(Subject):
    """Represents the Proxy in the Proxy design pattern."""

    def __init__(self) -> None:
        """Initializes the Proxy."""
        print(f"{datetime.now().strftime('%H:%M:%S')} Proxy: Initializing.")
        self._real_subject = RealSubject()

    def request(self) -> None:
        """Requests the Proxy to perform an action."""
        if self._real_subject.is_ready:
            print(
                f"{datetime.now().strftime('%H:%M:%S')} Proxy: Forwarding request to RealSubject."
            )
            self._real_subject.request()
        else:
            print(
                f"{datetime.now().strftime('%H:%M:%S')} Proxy: RealSubject is not ready."
            )


def main() -> None:
    """Demonstrates the Proxy design pattern.

    Remarks:
        Console output sample:
            17:29:06 Proxy: Initializing.
            17:29:06 RealSubject: Initializing.
            17:29:06 Proxy: RealSubject is not ready.
            17:29:09 Proxy: Forwarding request to RealSubject.
            17:29:09 RealSubject: Handling request.
    """
    proxy = Proxy()
    proxy.request()
    sleep(3)  # Wait for the RealSubject to be ready.
    proxy.request()


if __name__ == "__main__":
    main()
