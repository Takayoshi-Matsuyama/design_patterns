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

using GoF.Visitor;

Console.WriteLine("GoF Visitor Pattern Example");

var objectStructure = new ObjectStructure();
objectStructure.Attach(new ConcreteElementA());
objectStructure.Attach(new ConcreteElementB());

// Visitors extend the functionality of elements without modifying them.
// So we can also call visitors as "function extenders".
var visitor1 = new ConcreteVisitor1();
var visitor2 = new ConcreteVisitor2();
objectStructure.Accept(visitor1);
objectStructure.Accept(visitor2);
