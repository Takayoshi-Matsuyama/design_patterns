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
namespace GoF.Mediator;

/// <summary>
/// Represents a concrete implementation of the IColleague interface in the Mediator design pattern.
/// </summary>
public class ConcreteColleague1 : IColleague
{
    /// <summary>
    /// The mediator that facilitates communication between colleagues.
    /// </summary>
    private readonly IMediator _mediator;

    /// <summary>
    /// Initializes a new instance of the ConcreteColleague1 class with the specified mediator.
    /// </summary>
    /// <param name="mediator">The mediator to associate with this colleague.</param>
    public ConcreteColleague1(IMediator mediator)
    {
        _mediator = mediator;
        _mediator.RegisterColleague(this);
    }

    /// <summary>
    /// Sends a message to the mediator for communication with other colleagues.
    /// </summary>
    /// <param name="message">The message to send.</param>
    public void Send(string message)
    {
        Console.WriteLine($"ConcreteColleague1 sends: {message}");
        _mediator.Notify(this, message);
    }

    /// <summary>
    /// Receives a message from the mediator.
    /// </summary>
    /// <param name="message">The message received.</param>
    public void Receive(string message)
    {
        Console.WriteLine($"ConcreteColleague1 has received: {message}");
    }
}
