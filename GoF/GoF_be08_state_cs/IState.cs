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
/// Represents a state in the State design pattern.
/// </summary>
public interface IState
{
    /// <summary>
    /// Handles the behavior associated with this state.
    /// </summary>
    void Handle();

    /// <summary>
    /// Handles the behavior associated with this state using the specified context.
    /// </summary>
    /// <param name="context">The context in which the state operates.</param>
    /// <remarks>
    /// Autonomous state machine behavior can be implemented within the state itself,
    /// by changing the state of the context as needed.
    /// </remarks>
    void Handle(Context context);
}
