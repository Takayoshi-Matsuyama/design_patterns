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

// Filescope namespace (C# 10.0 or later)
namespace GoF.Interpreter;

/// <summary>
/// Represents the context in which the expressions are evaluated.
/// </summary>
/// <param name="inputValue">The input value to be processed by the expressions.</param>
/// <remarks>
/// Primary Constuctor (C#12 or later) is used to define the parameters
/// and initialize the fields of the Context class.
/// </remarks>
public class Context(int inputValue)
{
    /// <summary>
    /// Returns the input value provided to the context.
    /// </summary>
    public int InputValue { get; } = inputValue;

    /// <summary>
    /// Returns the output value after processing the expressions.
    /// </summary>
    public int OutputValue { get; private set; } = 0;

    /// <summary>
    /// Adds the specified value to the output value.
    /// </summary>
    /// <param name="value">The value to add to the output value.</param>
    public void AddToOutput(int value)
    {
        OutputValue += value;
    }
}