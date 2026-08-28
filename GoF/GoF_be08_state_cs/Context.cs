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
/// Represents the context in the State design pattern.
/// </summary>
/// <param name="state">The initial state of the context.</param>
/// <remarks>
/// Primary Constuctor (C#12 or later) is used to define the parameters
/// and initialize the fields of the Context class.
/// </remarks>
public class Context(IState state)
{
    /// <summary>
    /// Gets or sets the current state of the context.
    /// </summary>
    public IState State {get; set;} = state;

    /// <summary>
    /// Requests the current state to handle the behavior.
    /// </summary>
    public void Request()
    {
        State.Handle();
    }

    /// <summary>
    /// Requests the current state to handle the behavior using the specified context.
    /// </summary>
    public void RequestWithContext()
    {
        State.Handle(this);
    }
}
