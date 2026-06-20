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


class Colleague(ABC):

    @abstractmethod
    def send(self, message):
        pass

    @abstractmethod
    def receive(self, message):
        pass


class Mediator(ABC):

    @abstractmethod
    def notify(self, sender, message):
        pass


class ConcreteColleague1(Colleague):

    def __init__(self, mediator):
        self.mediator = mediator

    def send(self, message):
        self.mediator.notify(self, message)

    def receive(self, message):
        print(f"{self.__class__.__name__} received: {message}")


class ConcreteColleague2(Colleague):

    def __init__(self, mediator):
        self.mediator = mediator

    def send(self, message):
        self.mediator.notify(self, message)

    def receive(self, message):
        print(f"{self.__class__.__name__} received: {message}")


class ConcreteMediator(Mediator):

    def __init__(self):
        self.colleague1 = ConcreteColleague1(self)
        self.colleague2 = ConcreteColleague2(self)

    def notify(self, sender, message):
        if sender == self.colleague1:
            self.colleague2.receive(message)
        elif sender == self.colleague2:
            self.colleague1.receive(message)


if __name__ == "__main__":

    mediator = ConcreteMediator()
    mediator.colleague1.send("Hello from Colleague 1")
    mediator.colleague2.send("Hello from Colleague 2")
