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

using GoF.ChainOfResponsibility;

Console.WriteLine("GoF Chain of Responsibility Pattern Example");

IHandler handler2 = new ConcreteHandler2();
IHandler handler1 = new ConcreteHandler1(handler2);

var errorEvent1 = new ErrorEvent(1, "Error Message 1");
var errorEvent2 = new ErrorEvent(2, "Error Message 2");

handler1.HandleRequest(errorEvent1);
handler1.HandleRequest(errorEvent2);
