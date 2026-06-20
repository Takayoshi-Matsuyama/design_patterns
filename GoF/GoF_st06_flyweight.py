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


class Flyweight(ABC):

    @abstractmethod
    def operation(self, extrinsic_state):
        pass


class ConcreteFlyweight(Flyweight):

    def __init__(self, intrinsic_state):
        self.intrinsic_state = intrinsic_state

    def operation(self, extrinsic_state):
        print(
            f"Intrinsic State: {self.intrinsic_state}, Extrinsic State: {extrinsic_state}"
        )


class UnsharedConcreteFlyweight(Flyweight):

    def __init__(self, intrinsic_state):
        self.intrinsic_state = intrinsic_state

    def operation(self, extrinsic_state):
        print(
            f"Unshared Intrinsic State: {self.intrinsic_state}, Extrinsic State: {extrinsic_state}"
        )


class FlyweightFactory:

    def __init__(self):
        self.flyweights = {}

    def get_flyweight(self, intrinsic_state):
        if intrinsic_state not in self.flyweights:
            self.flyweights[intrinsic_state] = ConcreteFlyweight(intrinsic_state)
        return self.flyweights[intrinsic_state]

    def get_unshared_flyweight(self, intrinsic_state):
        return UnsharedConcreteFlyweight(intrinsic_state)


if __name__ == "__main__":

    factory = FlyweightFactory()

    flyweight1 = factory.get_flyweight("State1")
    flyweight2 = factory.get_flyweight("State1")
    flyweight3 = factory.get_flyweight("State2")

    flyweight1.operation("Extrinsic State A")
    flyweight2.operation("Extrinsic State B")
    flyweight3.operation("Extrinsic State C")

    unshared_flyweight = factory.get_unshared_flyweight("Unshared State")
    unshared_flyweight.operation("Extrinsic State D")

    print(
        f"Flyweight1 and Flyweight2 are the same instance: {flyweight1 is flyweight2=}"
    )
    print(
        f"Flyweight1 and Flyweight3 are the same instance: {flyweight1 is flyweight3=}"
    )
    print(
        f"Unshared Flyweight is a different instance: {unshared_flyweight is flyweight1=}"
    )
