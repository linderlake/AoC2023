#!/bin/bash
if [ ! -d "/home/vscode/AoCHelper" ]; then
    echo "AoCHelper not found, cloning..."
    git clone git@github.com:linderlake/AoCHelper.git /home/vscode/AoCHelper > /dev/null 2>&1 || echo "Failed to clone AoCHelper"
fi
echo "Updating AoCHelper..."
git -C /home/vscode/AoCHelper pull > /dev/null 2>&1 || echo "Failed to update AoCHelper"

echo "Verifying symlinks..."
mkdir -p ../lib/AocHelper
if [ ! -L "../lib/AocHelper/libAoCHelper.a" ]; then
    echo "Creating symlink to libAoCHelper.a"
    ln -s /home/vscode/AoCHelper/build/libAoCHelper.a ../lib/AocHelper/libAoCHelper.a 
fi

mkdir -p ../lib/AocHelper/include

if [ ! -L "../lib/AocHelper/include/AoCHelper.h" ]; then
    echo "Creating symlink to AoCHelper.h"
    ln -s /home/vscode/AoCHelper/src/AoCHelper.h ../lib/AocHelper/include/AoCHelper.h
fi

if [ ! -L "../lib/AocHelper/include/helper_functions.h" ]; then
    echo "Creating symlink to helper_functions.h"
    ln -s /home/vscode/AoCHelper/src/helper_functions.h ../lib/AocHelper/include/helper_functions.h
fi