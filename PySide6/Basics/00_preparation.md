
# Create Python Virtual Environment
python -m venv .venv 

# Activate Virtual Environment
.venv\Scripts\activate 

# Deactivate Virtual Environment (At the end of work)
deactivate

# Install libraries
python -m pip install --upgrade pip
pip install PySide6 opencv-python numpy
