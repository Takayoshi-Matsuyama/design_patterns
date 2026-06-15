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

#ifndef SUBJECT_H_
#define SUBJECT_H_

class Subject {
    public:
        virtual ~Subject() = default;  // Virtual destructor for proper cleanup of derived classes
        virtual void Request() = 0;  // Pure virtual function making this an abstract class
};

#endif  // SUBJECT_H_
