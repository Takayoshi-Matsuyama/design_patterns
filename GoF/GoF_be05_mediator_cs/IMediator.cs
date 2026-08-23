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
/// Represents a mediator in the Mediator design pattern.
/// </summary>
public interface IMediator
{
    /// <summary>
    /// Registers a colleague with the mediator for communication.
    /// </summary>
    /// <param name="colleague">The colleague to register.</param>
    void RegisterColleague(IColleague colleague);

    /// <summary>
    /// Notifies the mediator of a message sent by a colleague,
    /// allowing the mediator to facilitate communication between colleagues.
    /// </summary>
    /// <param name="sender">The colleague sending the message.</param>
    /// <param name="message">The message sent by the colleague.</param>
    void Notify(IColleague sender, string message);
}
