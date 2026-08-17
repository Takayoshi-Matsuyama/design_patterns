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

using GoF.Interpreter;

Console.WriteLine("GoF Interpreter Pattern Example");

var context = new Context(5);
var terminalExpression = new TerminalExpression();
terminalExpression.Interpret(context);
Console.WriteLine($"Terminal Expression interpreted. Output: {context.OutputValue}");

var context2 = new Context(10);
var nonTerminalExpression = new NonTerminalExpression(
    terminalExpression,
    terminalExpression
);
nonTerminalExpression.Interpret(context2);
Console.WriteLine($"Non-Terminal Expression interpreted. Output: {context2.OutputValue}");
