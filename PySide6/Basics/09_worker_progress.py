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
from PySide6.QtCore import (
    QObject,
    QRunnable,
    QThreadPool,
    Signal,
    Slot,
)
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QProgressBar,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class WorkerSignals(QObject):
    """Represents the signals available for a worker thread."""

    progress = Signal(int)  # Signal to indicate progress percentage
    finished = Signal()  # Signal to indicate the worker has finished


class Worker(QRunnable):
    """Represents a worker thread for executing a task with progress reporting."""

    def __init__(self):
        """Initializes the worker and its signals."""
        super().__init__()
        self.signals = WorkerSignals()

    @Slot()
    def run(self):
        """Runs the task and emits progress signals."""
        for i in range(101):
            time.sleep(0.05)  # A time-consuming task
            self.signals.progress.emit(i)
        self.signals.finished.emit()


class MainWindow(QMainWindow):
    """Represents the main window for the worker progress example."""

    def __init__(self):
        """Initializes the main window and its widgets."""
        super().__init__()

        self.setWindowTitle("Worker Progress Example")
        self.resize(324, 200)

        self.label = QLabel("Progress:")
        self.progress_bar = QProgressBar()
        self.button = QPushButton("Start")

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.progress_bar)
        layout.addWidget(self.button)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        self.button.clicked.connect(self.start_worker)

        self.thread_pool = QThreadPool()

    def start_worker(self):
        """Starts the worker thread and connects its signals."""
        self.label.setText("Executing Task...")
        worker = Worker()
        worker.signals.progress.connect(self.progress_bar.setValue)
        worker.signals.finished.connect(self.worker_finished)
        self.thread_pool.start(worker)

    def worker_finished(self):
        """Handles the completion of the worker thread."""
        self.label.setText("Task Completed!")


def main():
    """Executes the main application loop."""
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
