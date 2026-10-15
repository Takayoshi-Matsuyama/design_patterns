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
import time
from PySide6.QtCore import QRunnable, QThreadPool
from PySide6.QtWidgets import (
    QApplication,
    QPushButton,
    QMainWindow,
)


class Worker(QRunnable):
    """Worker class for executing concurrent tasks."""

    def run(self):
        """Runs the concurrent task."""
        print("Starting concurrent task....")
        time.sleep(2)  # Simulate a time-consuming task
        print("Concurrent task finished.")


class MainWindow(QMainWindow):
    """Main window for the concurrent example application."""

    def __init__(self):
        """Initialize the main window."""
        super().__init__()
        self.setWindowTitle("Concurrent Example")
        self.resize(324, 200)

        # Initialize the thread pool for concurrent task execution.
        self.thread_pool = QThreadPool()
        print(f"Maximum thread count: {self.thread_pool.maxThreadCount()}")

        # Setup the trigger button for executing concurrent tasks.
        button = QPushButton("Execute Concurrent Task")
        button.clicked.connect(self.on_execute_button_clicked)
        self.setCentralWidget(button)

    def on_execute_button_clicked(self):
        """Executes a concurrent task."""
        worker = Worker()
        self.thread_pool.start(worker)


def main():
    """Run the main application loop."""
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
