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


class Product:
    def __init__(self, name):
        self.name = name


class Builder:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def build_part(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def get_result(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteBuilder(Builder):
    def __init__(self):
        self.product = None

    def build_part(self):
        self.product = Product("Example Product")

    def get_result(self):
        return self.product


class Director:
    def __init__(self, builder):
        self._builder = builder

    def construct(self):
        self._builder.build_part()


if __name__ == "__main__":
    builder = ConcreteBuilder()
    director = Director(builder)
    director.construct()
    product = builder.get_result()
    print(f"Product created: {product.name}")
