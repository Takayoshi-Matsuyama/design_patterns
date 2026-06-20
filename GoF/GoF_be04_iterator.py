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


class Aggregate(ABC):

    @abstractmethod
    def create_iterator(self):
        pass


class ConcreteAggregate(Aggregate):

    def __init__(self):
        self._items = ["A", "B", "C", "D", "E"]

    def create_iterator(self):
        return ConcreteIterator(self)


class Iterator(ABC):

    @abstractmethod
    def first(self):
        pass

    @abstractmethod
    def next(self):
        pass

    @abstractmethod
    def is_done(self):
        pass

    @abstractmethod
    def current_item(self):
        pass


class ConcreteIterator(Iterator):

    def __init__(self, aggregate):
        self._aggregate = aggregate
        self._current = 0

    def first(self):
        self._current = 0

    def next(self):
        self._current += 1

    def is_done(self):
        return self._current >= len(self._aggregate._items)

    def current_item(self):
        if not self.is_done():
            return self._aggregate._items[self._current]
        else:
            raise StopIteration


if __name__ == "__main__":

    aggregate = ConcreteAggregate()
    iterator = aggregate.create_iterator()

    print("Iterating over the aggregate:")
    while not iterator.is_done():
        print(iterator.current_item())
        iterator.next()
