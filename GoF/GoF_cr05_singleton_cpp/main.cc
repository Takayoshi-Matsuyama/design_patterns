// Copyright 2026 Takayoshi Matsuyama
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>

#include "singleton.h"

int main() {
  std::cout << "GoF Singleton Pattern Example\n";

  sin_ptn::Singleton& singleton1 = sin_ptn::Singleton::GetInstance();
  sin_ptn::Singleton& singleton2 = sin_ptn::Singleton::GetInstance();

  std::cout << "singleton1 address: " << &singleton1 << "\n";
  std::cout << "singleton2 address: " << &singleton2 << "\n";

  return 0;
}
