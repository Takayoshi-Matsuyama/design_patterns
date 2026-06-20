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


class Implementor(ABC):

    @abstractmethod
    def operation_impl(self):
        pass


class ConcreteImplementorA(Implementor):

    def operation_impl(self):
        return "ConcreteImplementorA operation"


class ConcreteImplementorB(Implementor):

    def operation_impl(self):
        return "ConcreteImplementorB operation"


class Abstraction(ABC):

    @abstractmethod
    def operation(self):
        pass


class RefinedAbstraction(Abstraction):

    def __init__(self, implementor):
        self._implementor = implementor

    def operation(self):
        return f"RefinedAbstraction: {self._implementor.operation_impl()}"


if __name__ == "__main__":

    implementor_a = ConcreteImplementorA()
    abstraction_a = RefinedAbstraction(implementor_a)
    print(abstraction_a.operation())

    implementor_b = ConcreteImplementorB()
    abstraction_b = RefinedAbstraction(implementor_b)
    print(abstraction_b.operation())
