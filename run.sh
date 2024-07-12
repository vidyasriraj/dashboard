PROJECT_DIR=$(pwd)

# Navigate to the project directory
cd "$PROJECT_DIR"
sudo qmake dashboard.pro
sudo make


./dashboard
