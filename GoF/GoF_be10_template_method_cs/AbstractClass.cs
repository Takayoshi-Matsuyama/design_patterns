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
namespace GoF.TemplateMethod;

/// <summary>
/// Represents the abstract class in the Template Method pattern.
/// </summary>
public abstract class AbstractClass
{
    /// <summary>
    /// Executes the first primitive operation.
    /// </summary>
    protected abstract void ExecutePrimitiveOperation1();

    /// <summary>
    /// Executes the second primitive operation.
    /// </summary>
    protected abstract void ExecutePrimitiveOperation2();

    /// <summary>
    /// Executes the template method,
    /// which calls the primitive operations in a defined sequence.
    /// </summary>
    public void ExecuteTemplateMethod()
    {
        ExecutePrimitiveOperation1();
        ExecutePrimitiveOperation2();
    }
}
