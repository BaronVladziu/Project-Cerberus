#!/bin/bash
set -euo pipefail

mkdir -p build
cd build
cmake ..
make
./Project-Cerberus
