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


class Prototype:
    def __init__(self):
        raise NotImplementedError("You should implement the clone method.")

    def clone(self):
        raise NotImplementedError("You should implement the clone method.")


class ConcretePrototype1(Prototype):
    def __init__(self):
        pass

    def clone(self):
        return ConcretePrototype1()


class ConcretePrototype2(Prototype):
    def __init__(self):
        pass

    def clone(self):
        return ConcretePrototype2()


if __name__ == "__main__":
    prototype1 = ConcretePrototype1()
    clone1 = prototype1.clone()
    print(f"Cloned object of type: {type(clone1).__name__}")

    prototype2 = ConcretePrototype2()
    clone2 = prototype2.clone()
    print(f"Cloned object of type: {type(clone2).__name__}")
