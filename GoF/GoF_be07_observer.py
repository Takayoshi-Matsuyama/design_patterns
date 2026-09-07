"""
Implementation of the Observer design pattern.

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


class Observer(ABC):
    """Represents the Observer in the Observer design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def update(self, subject: Subject) -> None:
        """Updates the observer with the state of the subject.

        Args:
            subject (Subject): The subject that notifies the observer of a state change.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteObserver(Observer):
    """Represents a concrete implementation of the Observer in the Observer design pattern."""

    def __init__(self, subject: Subject) -> None:
        """Initializes the ConcreteObserver with a subject to observe.

        Args:
            subject (Subject): The subject to be observed.
        """
        self._observer_state: str = ""  # Empty string
        self._subject: Subject = subject
        self._subject.attach(self)

    def update(self, subject: Subject) -> None:
        """Updates the observer with the state of the subject.

        Args:
            subject (Subject): The subject that notifies the observer of a state change.
        """
        if isinstance(subject, StateSubject):
            self._observer_state = subject.get_state()
            print(f"ConcreteObserver: Updated observer state to {self._observer_state}")


class Subject(ABC):
    """Represents the Subject in the Observer design pattern."""

    @abstractmethod
    def attach(self, observer: Observer) -> None:
        """Attaches an observer to the subject.

        Args:
            observer (Observer): The observer to be attached.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def detach(self, observer: Observer) -> None:
        """Detaches an observer from the subject.

        Args:
            observer (Observer): The observer to be detached.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def notify(self) -> None:
        """Notifies all attached observers of a state change."""
        ...  # Should be implemented by concrete subclasses.


class StateSubject(Subject):
    """Represents a Subject that has a state in the Observer design pattern."""

    @abstractmethod
    def set_state(self, state: str) -> None:
        """Sets the state of the subject.

        Args:
            state (str): The new state of the subject.
        """
        ...  # Should be implemented by concrete subclasses.

    @abstractmethod
    def get_state(self) -> str:
        """Gets the current state of the subject.

        Returns:
            str: The current state of the subject.
        """
        ...  # Should be implemented by concrete subclasses.


class ConcreteSubject(StateSubject):
    """Represents a concrete implementation of the Subject in the Observer design pattern."""

    def __init__(self):
        """Initializes the ConcreteSubject."""
        self._observers: list[Observer] = []
        self._subject_state: str = ""  # Empty string

    def attach(self, observer: Observer) -> None:
        """Attaches an observer to the subject.

        Args:
            observer (Observer): The observer to be attached.
        """
        self._observers.append(observer)

    def detach(self, observer: Observer) -> None:
        """Detaches an observer from the subject.

        Args:
            observer (Observer): The observer to be detached.
        """
        self._observers.remove(observer)

    def notify(self) -> None:
        """Notifies all attached observers of a state change."""
        for observer in self._observers:
            observer.update(self)

    def set_state(self, state: str) -> None:
        """Sets the state of the subject and notifies observers.

        Args:
            state (str): The new state of the subject.
        """
        self._subject_state = state
        self.notify()

    def get_state(self) -> str:
        """Gets the current state of the subject.

        Returns:
            str: The current state of the subject.
        """
        return self._subject_state


def main() -> None:
    """Demonstrates the Observer design pattern."""
    subject = ConcreteSubject()
    observer1 = ConcreteObserver(subject)
    observer2 = ConcreteObserver(subject)

    subject.set_state("State 1")
    subject.set_state("State 2")

    subject.detach(observer1)
    subject.set_state("State 3")

    subject.detach(observer2)
    subject.set_state("State 4")


if __name__ == "__main__":
    main()
