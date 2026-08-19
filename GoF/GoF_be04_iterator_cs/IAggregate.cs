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
namespace GoF.Iterator;

/// <summary>
/// Represents the aggregate interface of Iterator pattern.
/// </summary>
/// <typeparam name="T">The type of elements in the aggregate object.</typeparam>
public interface IAggregate<T>
{
    /// <summary>
    /// Retrieves the number of elements in the aggregate object.
    /// </summary>
    int Count { get; }

    /// <summary>
    /// Adds an item to the aggregate object.
    /// </summary>
    /// <param name="item">The item to add to the aggregate object.</param>
    void Add(T item);

    /// <summary>
    /// Creates an iterator for the aggregate object.
    /// </summary>
    /// <returns>An iterator for the aggregate object.</returns>
    IIterator<T> CreateIterator();

    /// <summary>
    /// Retrieves the number of elements in the aggregate object.
    /// </summary>
    /// <returns>The number of elements in the aggregate object.</returns>
    int GetSize();

    /// <summary>
    /// Retrieves the item at the specified index in the aggregate object.
    /// </summary>
    /// <param name="index">The zero-based index of the item to retrieve.</param>
    /// <returns>The item at the specified index in the aggregate object.</returns>
    T GetItem(int index);
}
