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
namespace GoF.Interpreter;

/// <summary>
/// Represents a non-terminal expression in the interpreter pattern.
/// </summary>
/// <param name="expression1">The first sub-expression.</param>
/// <param name="expression2">The second sub-expression.</param>
/// <remarks>
/// Primary Constuctor (C#12 or later) is used to define the parameters
/// and initialize the fields of the NonTerminalExpression class.
/// </remarks>
public class NonTerminalExpression(
    IAbstractExpression expression1,
    IAbstractExpression expression2) : IAbstractExpression
{
    /// <summary>
    /// The first sub-expression to be interpreted.
    /// </summary>
    private readonly IAbstractExpression _expression1 = expression1;

    /// <summary>
    /// The second sub-expression to be interpreted.
    /// </summary>
    private readonly IAbstractExpression _expression2 = expression2;

    /// <summary>
    /// Interprets the non-terminal expression in the given context by interpreting its sub-expressions.
    /// </summary>
    /// <param name="context">The context in which the non-terminal expression is evaluated.</param>
    public void Interpret(Context context)
    {
        _expression1.Interpret(context);
        _expression2.Interpret(context);
    }
}
