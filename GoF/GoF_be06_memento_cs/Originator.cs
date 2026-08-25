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
/// Represents the Originator class for Memento design pattern.
/// </summary>
/// <param name="state">The initial state of the originator.</param>
/// <remarks>
/// Primary Constructor (C#12 or later) is used to define the parameters
/// and initialize the properties of the Originator class.
/// </remarks>
public class Originator(string state)
{
    /// <summary>
    /// Retrieves or sets the state of the originator object.
    /// </summary>
    public string State {get; set;} = state;

    /// <summary>
    /// Creates a memento that captures the current state of the originator.
    /// </summary>
    /// <returns>The memento capturing the current state of the originator.</returns>
    public IMemento CreateMemento()
    {
        return new Memento(State);
    }

    /// <summary>
    /// Sets the state of the originator from the given memento.
    /// </summary>
    /// <param name="memento">The memento from which to restore the state of the originator.</param>
    /// <exception cref="ArgumentException">Thrown when the provided memento is not of the expected type.</exception>
    public void SetMemento(IMemento memento)
    {
        if (memento is Memento m)
        {
            State = m.State;
        }
        else
        {
            throw new ArgumentException("Invalid memento type.", nameof(memento));
        }
    }

    /// <summary>
    /// Represents the Memento class for Memento design pattern.
    /// </summary>
    /// <param name="State">The state of the originator captured by the memento.</param>
    /// <remarks>
    /// (1) This record is for hiding the Memento implementation inside the Originator class.
    /// (2) Record type (C# 9.0 or later) is used to define the parameters
    ///     and initialize the properties of the Memento.
    /// </remarks>
    private record Memento(string State) : IMemento;
}
