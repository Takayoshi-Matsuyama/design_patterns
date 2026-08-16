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
namespace GoF.Command;

/// <summary>
/// Represents a concrete implementation of the ICommand interface in the Command design pattern.
/// </summary>
public class ConcreteCommand : ICommand
{
    /// <summary>
    /// The name of the command.
    /// </summary>
    private string _name;

    /// <summary>
    /// The receiver that will perform the action when the command is executed.
    /// </summary>
    private readonly IReceiver _receiver;

    /// <summary>
    /// Initializes a new instance of the ConcreteCommand class.
    /// </summary>
    /// <param name="name">The name of the command.</param>
    /// <param name="receiver">The receiver that will perform the action when the command is executed.</param>
    public ConcreteCommand(string name, IReceiver receiver)
    {
        _name = name;
        _receiver = receiver;
    }

    /// <summary>
    /// Executes the command by invoking the action on the receiver.
    /// </summary>
    public void Execute()
    {
        _receiver.Action();
    }

    /// <summary>
    /// Returns the name of the command.
    /// </summary>
    public string Name => _name;
}
