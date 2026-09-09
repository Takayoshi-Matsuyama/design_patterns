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

#ifndef DESIGN_PTN_GEN05_SIN_SINGLETON_H_
#define DESIGN_PTN_GEN05_SIN_SINGLETON_H_

namespace sin_ptn {

// Represents the singleton class in the singleton design pattern.
class Singleton {
 public:
  // Returns the only one instance of the Singleton class.
  // Note: The instance is created on the first call to this method.
  static Singleton& GetInstance() {
    // Note: Using keyword 'static' ensures that
    //       the instance is created only once.
    static Singleton instance;
    return instance;
  }

 private:
  // Constructs a new instance of the Singleton class.
  // Note: The constructor is private to prevent direct instantiation.
  Singleton() = default;

  // Destructs the Singleton instance.
  // Note: The destructor is private to prevent direct destruction.
  ~Singleton() = default;

  // Delete copy constructor to prevent copying.
  Singleton(const Singleton&) = delete;

  // Delete assignment operator to prevent assignment.
  Singleton& operator=(const Singleton&) = delete;

  // Delete move constructor to prevent moving.
  Singleton(Singleton&&) = delete;

  // Delete move assignment operator to prevent move assignment.
  Singleton& operator=(Singleton&&) = delete;
};

} // namespace sin_ptn

#endif // DESIGN_PTN_GEN05_SIN_SINGLETON_H_
