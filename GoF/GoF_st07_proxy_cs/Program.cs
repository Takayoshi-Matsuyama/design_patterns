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

using GoF.Proxy;

Console.WriteLine("GoF Proxy Example");

var proxy = new Proxy();

// Send request to the proxy for the first time.
// At this point, the RealSubject may not be ready yet.
// The proxy will handle this scenario appropriately.
proxy.Request();

// Wait for the RealSubject to become ready.
await Task.Delay(2000);

// Send request again.
proxy.Request();
