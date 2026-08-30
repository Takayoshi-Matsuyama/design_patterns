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
namespace GoF.Flyweight;

/// <summary>
/// Represents a concrete implementation of an unshared flyweight object.
/// </summary>
public class UnsharedConcreteFlyweight : IFlyweight
{
    /// <summary>
    /// Gets the intrinsic state of the unshared concrete flyweight.
    /// </summary>
    public int IntrinsicState { get; private set; } = 0;

    /// <summary>
    /// Executes an operation using the provided extrinsic state.
    /// </summary>
    /// <param name="extrinsicState">The extrinsic state to be used in the operation.</param>
    public void ExecuteOperation(int extrinsicState)
    {
        IntrinsicState += extrinsicState;
        Console.WriteLine($"UnsharedConcreteFlyweight: Updated intrinsic state to {IntrinsicState}");
    }

    /// <summary>
    /// Returns a string representation of the unshared concrete flyweight, including its intrinsic state.
    /// </summary>
    /// <returns>A string representation of the unshared concrete flyweight, including its intrinsic state.</returns>
    public override string ToString() => $"UnsharedConcreteFlyweight: IntrinsicState = {IntrinsicState}";
}
