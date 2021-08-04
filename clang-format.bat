Get-ChildItem -Path . -Directory -Recurse |
    foreach {
        cd $_.FullName
        &clang-format -i -style=WebKit *.cpp
    }