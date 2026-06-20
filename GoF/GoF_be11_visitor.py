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


class Visitor(ABC):

    @abstractmethod
    def visit(self, element):
        pass


class Element(ABC):

    @abstractmethod
    def accept(self, visitor):
        pass


class ConcreteVisitor1(Visitor):

    def visit(self, element):
        print(f"ConcreteVisitor #1: Visiting {element.__class__.__name__}")


class ConcreteVisitor2(Visitor):

    def visit(self, element):
        print(f"ConcreteVisitor #2: Visiting {element.__class__.__name__}")


class ConcreteElementA(Element):

    def accept(self, visitor):
        visitor.visit(self)


class ConcreteElementB(Element):

    def accept(self, visitor):
        visitor.visit(self)


if __name__ == "__main__":

    elements = [ConcreteElementA(), ConcreteElementB()]
    visitor1 = ConcreteVisitor1()
    visitor2 = ConcreteVisitor2()

    for element in elements:
        element.accept(visitor1)
        element.accept(visitor2)
