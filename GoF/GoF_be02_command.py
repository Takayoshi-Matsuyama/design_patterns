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


class Receiver:

    def action(self):
        print("Receiver: Performing the action.")


class Command(ABC):
    """Command interface declares common operations for subordinate command classes.
    By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
    we can ensure that any concrete implementation of Command must implement the execute method.
    """

    @abstractmethod
    def execute(self):
        pass


class ConcreteCommand(Command):

    def __init__(self, receiver):
        self._receiver = receiver

    def execute(self):
        self._receiver.action()


class Invoker:

    def __init__(self):
        self._command = None

    def set_command(self, command):
        self._command = command

    def execute_command(self):
        if self._command:
            self._command.execute()


if __name__ == "__main__":

    receiver = Receiver()
    command = ConcreteCommand(receiver)

    invoker = Invoker()
    invoker.set_command(command)
    invoker.execute_command()
