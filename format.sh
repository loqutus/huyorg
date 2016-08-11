#!/usr/bin/env bash
find . -iname *.h -o -iname *.cpp | xargs clang-format-3.8 -i -style=Google
