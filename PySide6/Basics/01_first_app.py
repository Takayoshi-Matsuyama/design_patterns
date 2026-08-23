from PySide6.QtWidgets import QApplication, QWidget

import sys

# Create the application instance
app = QApplication(sys.argv)

# Create a window instance and execute show() method to display the window
window = QWidget()
window.show()

# Start the application's event loop
app.exec()
