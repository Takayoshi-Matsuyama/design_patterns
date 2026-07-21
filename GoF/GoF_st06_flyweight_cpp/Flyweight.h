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

#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

// Represents a Flyweight interface
class Flyweight {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~Flyweight() = default;

  // Flyweight interface method to perform an operation with extrinsic state.
  // Pure virtual function to be implemented by concrete flyweight classes.
  virtual void Operation(int extrinsic_state) = 0;
};

#endif // FLYWEIGHT_H
