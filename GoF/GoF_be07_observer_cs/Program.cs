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

using GoF.Observer;

Console.WriteLine("GoF Observer Pattern Example");

var subject = new ConcreteSubject();
var observer1 = new ConcreteObserver("Observer 1");
var observer2 = new ConcreteObserver("Observer 2");

subject.Attach(observer1);
subject.Attach(observer2);

subject.State = "New State";

subject.Detach(observer1);

subject.State = "Another New State";
