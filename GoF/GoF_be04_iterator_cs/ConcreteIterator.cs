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
/// Represents the concrete iterator for Iterator pattern.
/// </summary>
/// <typeparam name="T">The type of elements in the aggregate object.</typeparam>
/// <remarks>
/// Primary Constuctor (C#12 or later) is used to define the parameters
/// and initialize the fields of the Context class.
/// </remarks>
public class ConcreteIterator<T>(ConcreteAggregate<T> aggregate) : IIterator<T>
{
    /// <summary>
    /// The aggregate object that this iterator traverses.
    /// </summary>
    private readonly ConcreteAggregate<T> _aggregate = aggregate;

    /// <summary>
    /// The current index of the iterator in the aggregate object.
    /// </summary>
    private int _currentIndex = 0;

    /// <summary>
    /// Sets the current to the first item.
    /// </summary>
    public void First()
    {
        _currentIndex = 0;
    }

    /// <summary>
    /// Advances the current to the next item.
    /// </summary>
    public void Next()
    {
        _currentIndex++;
    }

    /// <summary>
    /// Determines whether the iterator has reached the end of the aggregate object.
    /// </summary>
    /// <returns><c>true</c> if the iterator has reached the end of the aggregate object; otherwise, <c>false</c>.</returns>
    public bool IsDone()
    {
        return _currentIndex >= _aggregate.GetSize();
    }

    /// <summary>
    /// Retrieves the current item in the aggregate object.
    /// </summary>
    /// <returns>The current item in the aggregate object.</returns>
    /// <exception cref="InvalidOperationException">Thrown if the iterator has reached the end of the collection.</exception>
    public T CurrentItem()
    {
        if (IsDone())
        {
            throw new InvalidOperationException("Iterator has reached the end of the collection.");
        }

        return _aggregate.GetItem(_currentIndex);
    }
}
