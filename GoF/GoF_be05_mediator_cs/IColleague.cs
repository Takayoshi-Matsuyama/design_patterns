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
/// Represents a colleague in the Mediator design pattern.
/// </summary>
public interface IColleague
{
    /// <summary>
    /// Sends a message to the mediator for communication with other colleagues.
    /// </summary>
    /// <param name="message">The message to send to the mediator.</param>
    void Send(string message);

    /// <summary>
    /// Receives a message from the mediator.
    /// </summary>
    /// <param name="message">The message received from the mediator.</param>
    void Receive(string message);
}
