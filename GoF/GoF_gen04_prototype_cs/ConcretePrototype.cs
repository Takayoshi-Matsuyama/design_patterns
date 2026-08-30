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
namespace GoF.Prototype;

/// <summary>
/// Represents a concrete prototype implementation for the Prototype design pattern.
/// </summary>
public class ConcretePrototype(string name) : IPrototype
{
    /// <summary>
    /// Gets the name of the concrete prototype instance.
    /// </summary>
    public string Name { get; init; } = name;

    /// <summary>
    /// Gets the nested list of the concrete prototype instance.
    /// </summary>
    public List<List<string>>? NestedList { get; set; }

    /// <summary>
    /// Creates a clone (deep copy) of the current concrete prototype instance.
    /// </summary>
    /// <returns>A new instance that is a clone of the current concrete prototype.</returns>
    /// <remarks>
    /// string elelment is not cloned deeply because strings are immutable.
    /// </remarks>
    public IPrototype Clone()
    {
        return new ConcretePrototype(this.Name)
        {
            NestedList = this.NestedList?.Select(
                innerList => new List<string>(innerList)).ToList()
        };
    }
}
