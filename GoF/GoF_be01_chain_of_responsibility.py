"""
Implementation of the Chain of Responsibility design pattern.

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


class Handler(ABC):
    """Represents the Handler in the Chain of Responsibility design pattern.

    Note: By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
          we ensure that any concrete implementation must implement the decorated method.
    """

    @abstractmethod
    def handle_request(self):
        pass


class ConcreteHandler1(Handler):

    def __init__(self, successor=None):
        self._successor = successor

    def handle_request(self):
        print("ConcreteHandler1: Handling request.")
        if self._successor:
            self._successor.handle_request()


class ConcreteHandler2(Handler):

    def __init__(self, successor=None):
        self._successor = successor

    def handle_request(self):
        print("ConcreteHandler2: Handling request.")
        if self._successor:
            self._successor.handle_request()


if __name__ == "__main__":

    handler1 = ConcreteHandler1()
    handler2 = ConcreteHandler2(handler1)

    handler2.handle_request()
