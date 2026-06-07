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


class Strategy:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def algorithm_interface(self, a, b):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteStrategyA(Strategy):
    def __init__(self):
        pass

    def algorithm_interface(self, a, b):
        return a + b


class ConcreteStrategyB(Strategy):
    def __init__(self):
        pass

    def algorithm_interface(self, a, b):
        return a - b


class Context:
    def __init__(self, strategy):
        self._strategy = strategy

    def set_strategy(self, strategy):
        self._strategy = strategy

    def execute_strategy(self, a, b):
        return self._strategy.algorithm_interface(a, b)


if __name__ == "__main__":
    context = Context(ConcreteStrategyA())
    result = context.execute_strategy(5, 3)
    print(f"Addition Result: {result}")

    context.set_strategy(ConcreteStrategyB())
    result = context.execute_strategy(5, 3)
    print(f"Subtraction Result: {result}")
