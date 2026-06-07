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

    def add(self, component):
        raise NotImplementedError("This method should be implemented by subclasses")

    def remove(self, component):
        raise NotImplementedError("This method should be implemented by subclasses")

    def get_child(self, index):
        raise NotImplementedError("This method should be implemented by subclasses")


class Leaf(Component):
    def __init__(self):
        pass

    def operation(self):
        return "Leaf operation"


class Composite(Component):
    def __init__(self):
        self.children = []

    def operation(self):
        results = []
        for child in self.children:
            results.append(child.operation())
        return f"Composite operation: {', '.join(results)}"

    def add(self, component):
        self.children.append(component)

    def remove(self, component):
        self.children.remove(component)

    def get_child(self, index):
        return self.children[index]


if __name__ == "__main__":
    leaf1 = Leaf()
    leaf2 = Leaf()
    composite = Composite()
    composite.add(leaf1)
    composite.add(leaf2)

    print(composite.operation())
