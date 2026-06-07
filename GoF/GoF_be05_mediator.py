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


class Colleague:
    def __init__(self, mediator):
        raise NotImplementedError(
            "Colleague is an abstract class and cannot be instantiated directly."
        )

    def send(self, message):
        raise NotImplementedError("Subclasses must implement the send method.")

    def receive(self, message):
        raise NotImplementedError("Subclasses must implement the receive method.")


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


class Mediator:
    def __init__(self):
        raise NotImplementedError(
            "Mediator is an abstract class and cannot be instantiated directly."
        )

    def notify(self, sender, message):
        raise NotImplementedError("Subclasses must implement the notify method.")


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
