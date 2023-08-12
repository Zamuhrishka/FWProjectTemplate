@echo off

CD ..\src
FOR /R "%SourceCodePath%" %%f IN (*.cpp, *.h) DO (
    clang-format -i "%%f"
    echo %%f
)
