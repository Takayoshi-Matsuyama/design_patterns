"""
Implementation of the Facade design pattern.

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


class SubsystemA:
    """Represents Subsystem A in the Facade design pattern."""

    def operation_a(self) -> str:
        """Performs operation A.

        Returns:
            str: The result of operation A.
        """
        return "Result-A"


class SubsystemB:
    """Represents Subsystem B in the Facade design pattern."""

    def operation_b(self) -> str:
        """Performs operation B.

        Returns:
            str: The result of operation B.
        """
        return "Result-B"


class SubsystemC:
    """Represents Subsystem C."""

    def operation_c(self) -> str:
        """Performs operation C.

        Returns:
            str: The result of operation C.
        """
        return "Result-C"


class Facade:
    """Represents the Facade in the Facade design pattern."""

    def __init__(self) -> None:
        """Initializes the Facade with its subsystems."""
        self.subsystem_a = SubsystemA()
        self.subsystem_b = SubsystemB()
        self.subsystem_c = SubsystemC()

    def operation(self) -> str:
        """Performs the operation by delegating to the subsystems.

        Returns:
            str: The combined result of the subsystem operations.
        """
        result = []
        result.append(self.subsystem_a.operation_a())
        result.append(self.subsystem_b.operation_b())
        result.append(self.subsystem_c.operation_c())
        return f"Result: {' '.join(result)}"


def main() -> None:
    """Demonstrates the Facade design pattern."""
    facade = Facade()
    print(facade.operation())


if __name__ == "__main__":
    main()
