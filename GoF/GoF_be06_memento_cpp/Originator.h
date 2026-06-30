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

#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include "Memento.h"

#include <string>

class Originator {

    public:
        Originator() = default;

        void SetState(const std::string& state);

        std::string GetState() const;

        Memento CreateMemento() const;

        void SetMemento(const Memento& memento);

    private:
        std::string _state;
};

#endif // ORIGINATOR_H
