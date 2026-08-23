# Copyright 2026 Takayoshi Matsuyama
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Import PySide6 modules
from PySide6.QtWidgets import QApplication, QWidget

import sys

# Create the application instance
app = QApplication(sys.argv)

# Create a window instance and execute show() method to display the window
window = QWidget()
window.show()

# Start the application's event loop
app.exec()
