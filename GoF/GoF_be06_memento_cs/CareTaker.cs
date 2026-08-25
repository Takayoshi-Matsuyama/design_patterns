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
namespace GoF.Memento;

/// <summary>
/// Represents the Caretaker class for Memento design pattern.
/// </summary>
public class Caretaker
{
    /// <summary>
    /// The list of mementos that the caretaker manages.
    /// </summary>
    /// <remarks>
    /// Collection initializer syntax is used to initialize the list of mementos (C#12 or later).
    /// </remarks>
    private readonly List<IMemento> _mementos = [];

    /// <summary>
    /// Adds a memento to the caretaker's list of mementos.
    /// </summary>
    /// <param name="memento">The memento to add to the caretaker's list of mementos.</param>
    public void AddMemento(IMemento memento)
    {
        _mementos.Add(memento);
    }

    /// <summary>
    /// Retrieves a memento from the caretaker's list of mementos by index.
    /// </summary>
    /// <param name="index">The index of the memento to retrieve.</param>
    /// <returns>The memento at the specified index.</returns>
    /// <exception cref="ArgumentOutOfRangeException"></exception>
    public IMemento GetMemento(int index)
    {
        if (index < 0 || index >= _mementos.Count)
        {
            throw new ArgumentOutOfRangeException(nameof(index), "Index is out of range.");
        }
        return _mementos[index];
    }
}
