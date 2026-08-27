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

/// <summary>
/// Represents the subject in the Observer design pattern,
/// which maintains a list of observers and notifies them of any state changes.
/// </summary>
public interface ISubject
{
    /// <summary>
    /// Gets or sets the current state of the subject.
    /// </summary>
    string State { get; set; }

    /// <summary>
    /// Attaches an observer to the subject.
    /// </summary>
    /// <param name="observer">The observer to attach.</param>
    void Attach(IObserver observer);

    /// <summary>
    /// Detaches an observer from the subject.
    /// </summary>
    /// <param name="observer">The observer to detach.</param>
    void Detach(IObserver observer);

    /// <summary>
    /// Notifies all attached observers of a state change.
    /// </summary>
    void Notify();
}
