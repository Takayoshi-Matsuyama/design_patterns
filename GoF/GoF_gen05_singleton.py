"""
Implementation of the Singleton design pattern.

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

import threading
from typing import Self


class Singleton:
    """Singleton design pattern implementation in Python."""

    # class variable to hold the single instance of the class
    _instance = None

    # class variable to track if the instance has been initialized.
    _initialized = False

    # class variable to ensure thread-safe instance creation.
    _lock = threading.Lock()

    def __new__(cls) -> Self:
        """Override __new__ to control the creation of the instance.

        Returns:
            Self: The single instance of the class.
        """
        # Ensuring instance creation is thread-safe.
        with cls._lock:
            if cls._instance is None:
                # Create the instance by using the superclass's __new__ method.
                # The super class is 'object' in this case.
                cls._instance = super().__new__(cls)
            return cls._instance

    def __init__(self) -> None:
        """Initialize the Singleton instance."""
        # Initialize instance variables here if needed.
        if not self._initialized:
            # Perform initialization here.
            self._initialized = True


def main() -> None:
    """Entry point for the Singleton pattern demonstration."""
    s1 = Singleton()
    s2 = Singleton()

    print(f"{id(s1)=}\n{id(s2)=}")  # Output: same id for all instances
    print(f"{s1=}\n{s2=}")  # Output: same instance for all variables

    print(f"{s1 is s2=}")  # Output: True

    s1.value = 42
    print(f"{s2.value=}")  # Output: 42, since s1 and s2 are the same instance

    s2.value = 99
    print(f"{s1.value=}")  # Output: 99, since s1 and s2 are the same instance


if __name__ == "__main__":
    main()
