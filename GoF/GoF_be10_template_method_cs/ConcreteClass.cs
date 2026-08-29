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
/// Represents the concrete class in the Template Method pattern.
/// </summary>
public class ConcreteClass : AbstractClass
{
    /// <summary>
    /// Executes the first primitive operation.
    /// </summary>
    public override void ExecutePrimitiveOperation1()
    {
        Console.WriteLine("ConcreteClass: Executing Primitive Operation 1");
    }

    /// <summary>
    /// Executes the second primitive operation.
    /// </summary>
    public override void ExecutePrimitiveOperation2()
    {
        Console.WriteLine("ConcreteClass: Executing Primitive Operation 2");
    }
}
