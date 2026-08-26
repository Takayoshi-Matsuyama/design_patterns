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

"""Simple PySide6 application that hosts a Plotly figure.

This example demonstrates how to integrate Plotly visualizations
into a PySide6 application by rendering the Plotly figure as HTML
and displaying it in a web browser widget.
"""

import sys

import plotly.express as px
from PySide6.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget
from PySide6.QtWebEngineWidgets import QWebEngineView  # Web Browser Widget


class PlotlyHostingWindow(QMainWindow):
    """Represents a main window that hosts a Plotly figure in a web browser widget."""

    def __init__(self):
        """Initializes the main window and sets up the Plotly figure."""
        super().__init__()
        self.setWindowTitle("PySide6 + Plotly Hosting Window")
        self.resize(800, 600)

        main_widget = QWidget()
        self.setCentralWidget(main_widget)
        layout = QVBoxLayout(main_widget)

        # 1. QWebEngineView (Web Browser Widget)
        self.browser = QWebEngineView()
        layout.addWidget(self.browser)

        # 2. Create a Plotly figure
        fig = px.scatter(
            x=[1, 2, 3, 4, 5],
            y=[10, 14, 18, 24, 30],
            title="Sample Plotly Scatter Plot",
        )

        # 3. Convert the Plotly figure to HTML
        html = fig.to_html(include_plotlyjs="cdn")
        self.browser.setHtml(html)


def main():
    """Entry point for the application."""
    # Create the application instance.
    app = QApplication(sys.argv)

    # Create a window instance and execute show() method to display the window.
    window = PlotlyHostingWindow()
    window.show()

    # Start the application's event loop.
    # Return the exit code to the operating system when the event loop ends.
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
