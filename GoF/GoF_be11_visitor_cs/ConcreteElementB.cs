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
/// Represents a concrete element for the Visitor pattern.
/// </summary>
public class ConcreteElementB : IElement
{
    /// <summary>
    /// Gets the name of the element.
    /// </summary>
    public string Name => "ConcreteElementB";
    
    /// <summary>
    /// Accepts a visitor.
    /// </summary>
    /// <param name="visitor">The visitor to accept.</param>
    public void Accept(IVisitor visitor)
    {
        // Call the visitor's Visit method for this element.
        // This allows the visitor to perform operations specific to ConcreteElementB.
        // This mechanism realizes the functional extension
        // without modifying the element itself.
        visitor.Visit(this);
    }
}
