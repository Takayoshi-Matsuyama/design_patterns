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

using GoF.Command;

Console.WriteLine("GoF Command Pattern Example");

var receiver = new ConcreteReceiver();
var command1 = new ConcreteCommand("Command1", receiver);
var command2 = new ConcreteCommand("Command2", receiver);

var invoker = new Invoker();
invoker.SetCommand(command1);
invoker.SetCommand(command2);

invoker.ExecuteCommand();
invoker.ExecuteCommand();
invoker.ExecuteCommand();
