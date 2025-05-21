#!/bin/bash

# Use argument as target dir or default to current dir
target_dir=${1:-$(pwd)}

# Get all .cpp files in the target directory
cpp_files=("$target_dir"/*.cpp)

# Check if no cpp files found
if [ ${#cpp_files[@]} -eq 0 ]; then
    echo "No .cpp files found in $target_dir."
    exit 1
fi

# List files
echo "Available C++ files in $target_dir:"
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

# use [./run_cpp.sh {target_dir}] to run the script
# Example usage: ./run_cpp.sh /path/to/your/cpp/files