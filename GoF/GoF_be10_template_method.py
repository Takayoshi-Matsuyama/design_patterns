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


class AbstractClass(ABC):

    def template_method(self):
        self.primitive_operation1()
        self.primitive_operation2()

    @abstractmethod
    def primitive_operation1(self):
        pass

    @abstractmethod
    def primitive_operation2(self):
        pass


class ConcreteClass(AbstractClass):

    def primitive_operation1(self):
        print("ConcreteClass: Implementing primitive_operation1")

    def primitive_operation2(self):
        print("ConcreteClass: Implementing primitive_operation2")


if __name__ == "__main__":

    concrete = ConcreteClass()
    concrete.template_method()
