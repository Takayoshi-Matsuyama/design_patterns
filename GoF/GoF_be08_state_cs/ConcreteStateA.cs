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
namespace GoF.State;

/// <summary>
/// Represents ConcreteStateA in the State design pattern.
/// </summary>
public class ConcreteStateA : IState
{
    /// <summary>
    /// Handles the behavior associated with ConcreteStateA.
    /// </summary>
    public void Handle()
    {
        Console.WriteLine("ConcreteStateA: Specific behavior handled.");
    }

    /// <summary>
    /// Handles the behavior associated with ConcreteStateA using the specified context.
    /// </summary>
    /// <param name="context">The context in which the state operates.</param>
    public void Handle(Context context)
    {
        Console.WriteLine("ConcreteStateA: Specific behavior handled with context.");

        // Change the state of the context to ConcreteStateB.
        // (Autonomous state machine behavior)
        context.State = new ConcreteStateB();
    }
}
