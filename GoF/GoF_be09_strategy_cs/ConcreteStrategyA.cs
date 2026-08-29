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
namespace GoF.Strategy;

/// <summary>
/// A concrete strategy that implements the addition algorithm.
/// </summary>
public class ConcreteStrategyA : IStrategy
{
    /// <summary>
    /// Executes the addition algorithm.
    /// </summary>
    /// <param name="a">The first operand.</param>
    /// <param name="b">The second operand.</param>
    /// <returns>The result of adding <paramref name="a"/> and <paramref name="b"/>.</returns>
    public double AlgorithmInterface(double a, double b)
    {
        return a + b;
    }
}
