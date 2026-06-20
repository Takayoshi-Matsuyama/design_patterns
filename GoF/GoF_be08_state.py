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


class State(ABC):

    @abstractmethod
    def handle(self):
        pass


class ConcreteStateA(State):

    def handle(self):
        print("ConcreteStateA: Handling request in State A.")


class ConcreteStateB(State):

    def handle(self):
        print("ConcreteStateB: Handling request in State B.")


class Context:

    def __init__(self):
        self._state = None

    def set_state(self, state):
        self._state = state

    def request(self):
        if self._state:
            self._state.handle()
        else:
            print("Context: No state set to handle the request.")


if __name__ == "__main__":

    context = Context()

    state_a = ConcreteStateA()
    state_b = ConcreteStateB()

    context.set_state(state_a)
    context.request()

    context.set_state(state_b)
    context.request()
