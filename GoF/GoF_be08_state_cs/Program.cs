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

using GoF.State;

Console.WriteLine("GoF State Pattern Example");

var stateA = new ConcreteStateA();
var stateB = new ConcreteStateB();

Context context = new(stateA);
context.Request();

context.State = stateB;
context.Request();

// Advanced: Demonstrating the autonomous state machine behavior
// by repeatedly requesting the context to handle the behavior with context.
Console.WriteLine($"Current state: {context.State.GetType().Name}");
context.RequestWithContext();
Console.WriteLine($"Current state: {context.State.GetType().Name}");
context.RequestWithContext();
Console.WriteLine($"Current state: {context.State.GetType().Name}");
context.RequestWithContext();
Console.WriteLine($"Current state: {context.State.GetType().Name}");
context.RequestWithContext();
Console.WriteLine($"Current state: {context.State.GetType().Name}");
context.RequestWithContext();
Console.WriteLine($"Current state: {context.State.GetType().Name}");
