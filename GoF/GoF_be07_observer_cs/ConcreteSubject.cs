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
namespace GoF.Observer;

public class ConcreteSubject : ISubject
{
    /// <summary>
    /// Represents the list of observers attached to the subject.
    /// </summary>
    /// <remarks>
    /// This list is used to keep track of all observers that need to be notified
    /// whenever the state of the subject changes.
    /// </remarks>
    private readonly List<IObserver> _observers = new();

    private string _state = "Initial State";

    /// <summary>
    /// Gets or sets the current state of the subject.
    /// When the state is set, all attached observers are notified of the change.
    /// </summary>
    public string State
    {
        get => _state;
        set
        {
            _state = value;
            Notify();
        }
    }

    /// <summary>
    /// Attaches an observer to the subject.
    /// </summary>
    /// <param name="observer">The observer to attach.</param>
    public void Attach(IObserver observer)
    {
        _observers.Add(observer);
    }

    /// <summary>
    /// Detaches an observer from the subject.
    /// </summary>
    /// <param name="observer">The observer to detach.</param>
    public void Detach(IObserver observer)
    {
        _observers.Remove(observer);
    }

    /// <summary>
    /// Notifies all attached observers of a state change.
    /// </summary>
    public void Notify()
    {
        foreach (var observer in _observers)
        {
            observer.Update(this);
        }
    }
}
