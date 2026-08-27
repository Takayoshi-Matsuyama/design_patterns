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
/// Represents a concrete observer in the Observer design pattern, 
/// which gets notified of changes in the subject it is observing.
/// </summary>
/// <param name="Name">The name of the concrete observer.</param>
/// <remarks>
/// Primary Constuctor (C#12 or later) is used to define the parameters
/// and initialize the fields of the ConcreteObserver class.
/// </remarks>
public class ConcreteObserver(string Name) : IObserver
{
    /// <summary>
    /// Updates the concrete observer with the latest state from the subject.
    /// </summary>
    /// <param name="subject">The subject that has changed.</param>
    public void Update(ISubject subject)
    {
        Console.WriteLine($"Observer {Name} updated with subject state: {subject.State}");
    }
}
