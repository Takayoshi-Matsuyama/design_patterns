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
namespace GoF.AbstractFactory;

/// <summary>
/// Represents a concrete implementation of the abstract factory in the Abstract Factory design pattern.
/// </summary>
public class ConcreteFactory2 : IAbstractFactory
{
    /// <summary>
    /// Creates an instance of the concrete product A2.
    /// </summary>
    /// <returns>An instance of IAbstractProductA.</returns>
    public IAbstractProductA CreateProductA()
    {
        return new ProductA2();
    }

    /// <summary>
    /// Creates an instance of the concrete product B2.
    /// </summary>
    /// <returns>An instance of IAbstractProductB.</returns>
    public IAbstractProductB CreateProductB()
    {
        return new ProductB2();
    }
}
