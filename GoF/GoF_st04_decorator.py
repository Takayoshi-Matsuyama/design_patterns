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


class Component:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteComponent(Component):
    def __init__(self):
        pass

    def operation(self):
        return "ConcreteComponent operation"


class Decorator(Component):
    def __init__(self, component):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteDecoratorA(Decorator):
    def __init__(self, component):
        self._component = component
        self.added_state = "Added state in ConcreteDecoratorA"

    def operation(self):
        return f"ConcreteDecoratorA({self._component.operation()})"


class ConcreteDecoratorB(Decorator):
    def __init__(self, component):
        self._component = component

    def operation(self):
        return f"ConcreteDecoratorB({self._component.operation()})"

    def added_behavior(self):
        return "Added behavior in ConcreteDecoratorB"


if __name__ == "__main__":
    component = ConcreteComponent()
    print("Original component operation:")
    print(component.operation())

    decorator_a = ConcreteDecoratorA(component)
    print("\nAfter applying ConcreteDecoratorA:")
    print(decorator_a.operation())

    decorator_b = ConcreteDecoratorB(decorator_a)
    print("\nAfter applying ConcreteDecoratorB on top of ConcreteDecoratorA:")
    print(decorator_b.operation())
    print(decorator_b.added_behavior())
