#!/bin/bash

# Define the folder to modify
folder_to_modify="test"

# Search for .c files in the specified folder and its subdirectories
files=$(find "$folder_to_modify" -type f -name "*.c")

# Iterate over each .c file found
for file in $files; do
    # Replace instances of #include "binary_trees.h" with #include "../binary_trees.h"
    sed -i 's/#include "binary_trees.h"/#include "..\/binary_trees.h"/g' "$file"
    echo "Modified $file"
done

echo "Modification complete."

