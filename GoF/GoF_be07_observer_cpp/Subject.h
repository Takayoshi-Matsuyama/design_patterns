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

#ifndef DESIGN_PTN_BE07_OBS_SUBJECT_H_
#define DESIGN_PTN_BE07_OBS_SUBJECT_H_

#include "observer.h"

#include <string>

namespace obs_ptn {

// Represents the Subject interface in the Observer pattern.
class Subject {
 public:
  // Virtual destructor to ensure proper cleanup of derived classes.
  // This ensures that
  // when a derived class object is deleted through a base class pointer,
  // the derived class's destructor is called, preventing resource leaks.
  virtual ~Subject() = default;

  // Attaches an observer to the subject.
  virtual void Attach(class Observer* observer) = 0;

  // Detaches an observer from the subject.
  virtual void Detach(class Observer* observer) = 0;

  // Notifies all attached observers of a change in the subject's state.
  virtual void Notify() = 0;

  // Returns the current state of the subject.
  virtual std::string GetState() const = 0;
};

} // namespace obs_ptn

#endif // DESIGN_PTN_BE07_OBS_SUBJECT_H_
