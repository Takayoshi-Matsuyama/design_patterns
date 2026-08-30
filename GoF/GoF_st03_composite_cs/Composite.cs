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
/// Represents a composite component in the composite pattern.
/// </summary>
public class Composite : IComponent
{
    /// <summary>
    /// The list of child components contained within the composite.
    /// </summary>
    private readonly List<IComponent> _children = [];

    /// <summary>
    /// Executes the operation on the composite component and propagates it to its child components.
    /// </summary>
    public void Operation()
    {
        Console.WriteLine("Composite operation executed.");
        _children.ForEach(child => child.Operation());
    }

    /// <summary>
    /// Adds a child component to the composite.
    /// </summary>
    /// <param name="component">The child component to add.</param>
    public void Add(IComponent component) => _children.Add(component);

    /// <summary>
    /// Removes a child component from the composite.
    /// </summary>
    /// <param name="component">The child component to remove.</param>
    public void Remove(IComponent component) => _children.Remove(component);

    /// <summary>
    /// Gets the child component at the specified index.
    /// </summary>
    /// <param name="index">The index of the child component to retrieve.</param>
    /// <returns>The child component at the specified index, or null if it does not exist.</returns>
    public IComponent? GetChild(int index)
    {
        if (index < 0 || index >= _children.Count)
        {
            return null;
        }
        return _children[index];
    }
}
