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
namespace GoF.Builder;

/// <summary>
/// Represents a concrete builder in the Builder design pattern.
/// </summary>
public class ConcreteBuilder : IBuilder
{
    /// <summary>
    /// The product being constructed.
    /// </summary>
    private Product? _product = null;

    /// <summary>
    /// Builds a part of the product.
    /// </summary>
    public IBuilder BuildPart()
    {
        _product = new Product("Part");
        return this;
    }

    /// <summary>
    /// Gets the final product.
    /// </summary>
    /// <returns>The constructed product.</returns>
    /// <exception cref="InvalidOperationException">Thrown if the product has not been built yet.</exception>
    public Product GetResult()
    {
        var result = _product ?? throw new InvalidOperationException("Product has not been built.");
        
        // Reset the product to allow building a new one.
        _product = null;

        // Return the built product.
        return result;
    }
}
