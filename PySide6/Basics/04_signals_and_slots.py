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

import sys
from PySide6.QtGui import QAction
from PySide6.QtWidgets import (
    QApplication,
    QPushButton,
    QMainWindow,
    QToolBar,
    QStatusBar,
)


class MainWindow(QMainWindow):
    """Main window for the signals and slots example."""

    def __init__(self):
        """Initialize the main window."""
        super().__init__()
        self.setWindowTitle("Signals and Slots Example")
        self.resize(324, 200)

        # --- Button ---
        button = QPushButton("Click Me")
        # Connect the button's clicked signal to the handler method (slot).
        button.clicked.connect(self.on_button_clicked)
        self.setCentralWidget(button)

        # --- Toolbar ---
        toolbar = QToolBar("Main Toolbar")
        self.addToolBar(toolbar)
        toolbar_action = QAction("Toolbar Action", self)
        toolbar_action.setStatusTip("Click this toolbar action")
        toolbar_action.triggered.connect(self.on_toolbar_action_clicked)
        toolbar.addAction(toolbar_action)

        # --- Status Bar ---
        self.setStatusBar(QStatusBar(self))

    def on_button_clicked(self):
        """Handles the button click event."""
        print("Button clicked!")

    def on_toolbar_action_clicked(self):
        """Handles the toolbar button click event."""
        print("Toolbar action clicked!")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
