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
namespace GoF.Facade;

/// <summary>
/// Represents the Facade in the Facade pattern.
/// </summary>
public class Facade
{
    /// <summary>
    /// SubsystemA instance used by the Facade.
    /// </summary>
    private readonly SubsystemA _subsystemA = new();

    /// <summary>
    /// SubsystemB instance used by the Facade.
    /// </summary>
    private readonly SubsystemB _subsystemB = new();
    
    /// <summary>
    /// SubsystemC instance used by the Facade.
    /// </summary>
    private readonly SubsystemC _subsystemC = new();

    /// <summary>
    /// Executes a simplified operation that involves multiple subsystems.
    /// </summary>
    /// <returns>The combined result of the subsystems as a string.</returns>
    public string Operation()
    {
        var resultA = _subsystemA.OperationA();
        var resultB = _subsystemB.OperationB();
        var resultC = _subsystemC.OperationC();
        return $"Result: {resultA}, {resultB}, {resultC}";
    }
}
