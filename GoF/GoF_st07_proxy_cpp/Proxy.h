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

#ifndef PROXY_H_
#define PROXY_H_

#include "Subject.h"

class Proxy : public Subject {
    private:
        Subject& realSubject;  // Reference to the real subject that the proxy will control access to
    public:
        Proxy(Subject& subject);
        void Request() override;
};

#endif  // PROXY_H_
