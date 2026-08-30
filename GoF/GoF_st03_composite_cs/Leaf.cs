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
/// Represents a leaf component in the composite pattern.
/// </summary>
public class Leaf : IComponent
{
    /// <summary>
    /// Executes the operation on the leaf component.
    /// </summary>
    public void Operation() => Console.WriteLine("Leaf operation executed.");

    /// <summary>
    /// Adds a child component.
    /// </summary>
    /// <param name="component">The child component to add.</param>
    /// <exception cref="NotSupportedException">Thrown always because a leaf cannot have children.</exception>
    public void Add(IComponent component) => throw new NotSupportedException();

    /// <summary>
    /// Removes a child component.
    /// </summary>
    /// <param name="component">The child component to remove.</param>
    /// <exception cref="NotSupportedException">Thrown always because a leaf cannot have children.</exception>
    public void Remove(IComponent component) => throw new NotSupportedException();

    /// <summary>
    /// Gets the child component at the specified index.
    /// </summary>
    /// <param name="index">The index of the child component to retrieve.</param>
    /// <returns>null because a leaf does not have child components.</returns>
    public IComponent? GetChild(int index) => null;
}
