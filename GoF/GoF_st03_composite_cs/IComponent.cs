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
namespace GoF.Composite;

/// <summary>
/// Represents a component in the composite pattern.
/// </summary>
public interface IComponent
{
    /// <summary>
    /// Executes the operation on the component.
    /// </summary>
    void Operation();

    /// <summary>
    /// Adds a child component.
    /// </summary>
    void Add(IComponent component);

    /// <summary>
    /// Removes a child component.
    /// </summary>
    void Remove(IComponent component);

    /// <summary>
    /// Gets the child component at the specified index.
    /// </summary>
    /// <param name="index">The index of the child component to retrieve.</param>
    /// <returns>The child component at the specified index, or null if it does not exist.</returns>
    IComponent? GetChild(int index);
}
