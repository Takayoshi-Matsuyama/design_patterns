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

using GoF.Memento;

Console.WriteLine("GoF Memento Pattern Example");

var originator = new Originator("Initial State");
var caretaker = new Caretaker();

originator.State = "State 1";
caretaker.AddMemento(originator.CreateMemento());

originator.State = "State 2";
caretaker.AddMemento(originator.CreateMemento());

originator.State = "State 3";
caretaker.AddMemento(originator.CreateMemento());

Console.WriteLine($"Current State: {originator.State}");

originator.SetMemento(caretaker.GetMemento(0));
Console.WriteLine($"Restored State: {originator.State}");

originator.SetMemento(caretaker.GetMemento(1));
Console.WriteLine($"Restored State: {originator.State}");

originator.SetMemento(caretaker.GetMemento(2));
Console.WriteLine($"Restored State: {originator.State}");
