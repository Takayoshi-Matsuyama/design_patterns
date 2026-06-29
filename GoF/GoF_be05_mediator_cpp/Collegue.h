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

#ifndef COLLEGUE_H
#define COLLEGUE_H

#include <string>

class Collegue {
    public:
        virtual ~Collegue() = default;
        virtual void Send(const std::string& message) = 0;
        virtual void Receive(const std::string& message) = 0;
};

#endif // COLLEGUE_H
