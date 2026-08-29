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
namespace GoF.Visitor;

/// <summary>
/// Represents a collection of elements that can be visited by visitors.
/// </summary>
public class ObjectStructure
{
    /// <summary>
    /// The list of elements contained in the object structure.
    /// </summary>
    private readonly List<IElement> _elements = [];

    /// <summary>
    /// Attaches an element to the object structure.
    /// </summary>
    /// <param name="element">The element to attach to the object structure.</param>
    public void Attach(IElement element) => _elements.Add(element);

    /// <summary>
    /// Detaches an element from the object structure.
    /// </summary>
    /// <param name="element">The element to detach from the object structure.</param>
    public void Detach(IElement element) => _elements.Remove(element);

    /// <summary>
    /// Accepts a visitor and allows it to visit all elements in the object structure.
    /// </summary>
    /// <param name="visitor">The visitor to accept.</param>
    public void Accept(IVisitor visitor)
    {
        foreach (var element in _elements)
        {
            element.Accept(visitor);
        }
    }
}
