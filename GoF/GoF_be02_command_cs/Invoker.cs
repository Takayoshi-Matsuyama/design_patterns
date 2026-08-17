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
/// Represents the invoker in the Command design pattern.
/// </summary>
public class Invoker
{
    /// <summary>
    /// List of commands to be executed by the invoker.
    /// </summary>
    /// <remarks>
    /// Target-typed new expression (C# 9.0 or later) is used to initialize the list of commands.
    /// </remarks>
    private readonly Queue<ICommand> _commands = new();

    /// <summary>
    /// Sets the command to be executed by the invoker.
    /// </summary>
    /// <param name="command">The command to be added to the invoker's list of commands.</param>
    public void SetCommand(ICommand command)
    {
        _commands.Enqueue(command);
    }

    /// <summary>
    /// Executes the command that has been set in the invoker.
    /// </summary>
    public void ExecuteCommand()
    {
        if (_commands.Count > 0)
        {
            var command = _commands.Dequeue();
            Console.WriteLine($"Invoker: Executing command '{command.Name}'.");
            command.Execute();
        }
        else
        {
            Console.WriteLine("Invoker: No commands to execute.");
        }
    }
}
