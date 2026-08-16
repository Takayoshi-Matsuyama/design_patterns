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
/// Represents a concrete implementation of the IReceiver interface in the Command design pattern.
/// </summary>
public class ConcreteReceiver : IReceiver
{
    /// <summary>
    /// Executes the action associated with the command.
    /// </summary>
    public void Action()
    {
        Console.WriteLine("ConcreteReceiver: Action executed.");
    }
}
