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
/// Represents a context that uses a strategy to execute an algorithm.
/// </summary>
/// <param name="strategy">The strategy to be used by the context.</param>
public class Context(IStrategy strategy)
{
    /// <summary>
    /// The strategy to be used by the context.
    /// </summary>
    public IStrategy Strategy { get; set; } = strategy;

    /// <summary>
    /// Executes the algorithm defined by the current strategy.
    /// </summary>
    /// <param name="a">The first operand.</param>
    /// <param name="b">The second operand.</param>
    /// <returns>The result of the algorithm defined by the current strategy.</returns>
    /// <exception cref="InvalidOperationException">Thrown if the strategy is not set.</exception>
    public double ExecuteStrategy(double a, double b)
    {
        return Strategy.Execute(a, b);
    }
}
