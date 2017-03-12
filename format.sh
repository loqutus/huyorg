#!/usr/bin/env bash
find . -iname *.h -o -iname *.cpp | xargs clang-format -i -style="{BasedOnStyle: llvm, IndentWidth: 4}"

