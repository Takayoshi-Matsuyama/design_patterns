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
namespace GoF.Flyweight;

/// <summary>
/// Represents a factory for creating and managing flyweight objects.
/// </summary>
public class FlyweightFactory
{
    /// <summary>
    /// Gets the dictionary of flyweight objects managed by the factory.
    /// </summary>
    private readonly Dictionary<int, IFlyweight> _flyweights = [];

    /// <summary>
    /// Retrieves a flyweight object associated with the specified key.
    /// If the flyweight does not exist, a new one is created and added to the dictionary.
    /// </summary>
    /// <param name="key">The key identifying the flyweight object.</param>
    /// <param name="defaultIntrinsicState">The default intrinsic state to be used if a new flyweight is created.</param>
    /// <returns>The flyweight object associated with the specified key.</returns>
    public IFlyweight GetFlyweight(int key, int defaultIntrinsicState)
    {
        if (!_flyweights.TryGetValue(key, out var flyweight))
        {
            flyweight = new ConcreteFlyweight(defaultIntrinsicState);
            _flyweights[key] = flyweight;
        }
        return flyweight;
    }

    /// <summary>
    /// Retrieves an unshared flyweight object.
    /// Unlike shared flyweights, this object is not stored in the factory's dictionary.
    /// </summary>
    /// <param name="defaultIntrinsicState">The default intrinsic state to be used for the unshared flyweight.</param>
    /// <returns>An unshared flyweight object.</returns>
    public IFlyweight GetUnsharedFlyweight(int defaultIntrinsicState) =>
        new UnsharedConcreteFlyweight(defaultIntrinsicState);
}
