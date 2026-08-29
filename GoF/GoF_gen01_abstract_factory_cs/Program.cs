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

using GoF.AbstractFactory;

Console.WriteLine("GoF Abstract Factory Example");

var factory1 = new ConcreteFactory1();
IAbstractProductA productA1 = factory1.CreateProductA();
IAbstractProductB productB1 = factory1.CreateProductB();

productA1.ExecuteOperationA();
productB1.ExecuteOperationB();

var factory2 = new ConcreteFactory2();
IAbstractProductA productA2 = factory2.CreateProductA();
IAbstractProductB productB2 = factory2.CreateProductB();

productA2.ExecuteOperationA();
productB2.ExecuteOperationB();
