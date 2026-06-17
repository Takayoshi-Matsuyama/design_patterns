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


class Subject(ABC):
    """Subject interface declares common operations for subordinate subject classes.
    By inheriting from Abstract Base Class (ABC) and using the @abstractmethod decorator,
    we can ensure that any concrete implementation of Subject must implement the request method.
    """

    @abstractmethod
    def request(self):
        pass


class RealSubject(Subject):
    def __init__(self):
        pass

    def request(self):
        print("RealSubject: Handling request.")


class Proxy(Subject):
    def __init__(self):
        self._real_subject = None

    def request(self):
        print("Proxy: Logging request before forwarding to RealSubject.")
        if not self._real_subject:
            self._real_subject = RealSubject()
        self._real_subject.request()


if __name__ == "__main__":
    proxy = Proxy()
    proxy.request()
