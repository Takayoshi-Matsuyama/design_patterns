# Copyright 2026 Takayoshi Matsuyama
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from abc import ABC, abstractmethod


class Observer(ABC):

    @abstractmethod
    def update(self, subject):
        pass


class ConcreteObserver(Observer):

    def __init__(self, subject):
        self._observer_state = None
        self._subject = subject
        self._subject.attach(self)

    def update(self, subject):
        self._observer_state = subject.get_state()
        print(f"ConcreteObserver: Updated observer state to {self._observer_state}")


class Subject(ABC):

    @abstractmethod
    def attach(self, observer):
        pass

    @abstractmethod
    def detach(self, observer):
        pass

    @abstractmethod
    def notify(self):
        pass

    @abstractmethod
    def set_state(self, state):
        pass

    @abstractmethod
    def get_state(self):
        pass


class ConcreteSubject(Subject):

    def __init__(self):
        self._observers = []
        self._subject_state = None

    def attach(self, observer):
        self._observers.append(observer)

    def detach(self, observer):
        self._observers.remove(observer)

    def notify(self):
        for observer in self._observers:
            observer.update(self)

    def set_state(self, state):
        self._subject_state = state
        self.notify()

    def get_state(self):
        return self._subject_state


if __name__ == "__main__":

    subject = ConcreteSubject()
    observer1 = ConcreteObserver(subject)
    observer2 = ConcreteObserver(subject)

    subject.set_state("State 1")
    subject.set_state("State 2")

    subject.detach(observer1)
    subject.set_state("State 3")
