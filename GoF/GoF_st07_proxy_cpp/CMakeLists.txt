cmake_minimum_required(VERSION 3.10)
project(DesignPatternsApp)


# ディレクトリ内のすべての.cppファイルを自動で集めてビルドする設定
file(GLOB SOURCES "*.cpp")
add_executable(app ${SOURCES})
