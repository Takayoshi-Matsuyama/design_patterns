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

#ifndef DESIGN_PTN_BE03_INTERPRETER_CONTEXT_H_
#define DESIGN_PTN_BE03_INTERPRETER_CONTEXT_H_

namespace interpreter_ptn {

// Represents the context in the Interpreter pattern.
class Context {
 public:
  // Constructs a Context with the given input value
  // and initializes the output value to zero.
  // Apply "explicit" to prevent implicit conversions
  // and ensure that the constructor is only called with an integer value.
  explicit Context(int value) : input_value_(value), output_value_(0) {}

  // Gets the input value of the context.
  int GetInput() const { return input_value_; }

  // Adds the given value to the output value of the context.
  void AddToOutput(int value) { output_value_ += value; }

  // Gets the output value of the context.
  int GetOutput() const { return output_value_; }

 private:
  // The input value for the context, provided during construction.
  int input_value_;
  
  // The output value for the context,
  // initialized to zero and modified during interpretation.
  int output_value_;
};

} // namespace interpreter_ptn

#endif // DESIGN_PTN_BE03_INTERPRETER_CONTEXT_H_
