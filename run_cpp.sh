#!/bin/bash

# Get the directory where the script is called from
current_dir=$(pwd)

# Get all .cpp files in the current directory
cpp_files=("$current_dir"/*.cpp)

# Check if no cpp files found
if [ ${#cpp_files[@]} -eq 0 ]; then
    echo "No .cpp files found in $current_dir."
    exit 1
fi

# List files
echo "Available C++ files in $current_dir:"
for i in "${!cpp_files[@]}"; do
    echo "$((i+1)). $(basename "${cpp_files[$i]}")"
done

# Prompt user
read -p "Enter the number of the file to compile and run: " choice

# Validate input
if ! [[ "$choice" =~ ^[0-9]+$ ]] || [ "$choice" -lt 1 ] || [ "$choice" -gt ${#cpp_files[@]} ]; then
    echo "Invalid choice. Exiting."
    exit 1
fi

# Get selected file
selected_file="${cpp_files[$((choice-1))]}"
output_file="${selected_file%.cpp}.exe"

# Compile using clang++
clang++ "$selected_file" -o "$output_file"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run executable
echo -e "\nRunning $(basename "$output_file"):\n"
"$output_file"
if [ $? -ne 0 ]; then
    echo "Execution failed."
    exit 1
fi