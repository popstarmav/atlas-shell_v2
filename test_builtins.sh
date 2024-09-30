#!/bin/bash

# Function to run a command in the shell and check the output
run_test() {
    expected_output="$1"
    command="$2"
    
    # Run the command in your shell and capture the output
    output=$(echo "$command" | ./hsh)  # Run the command through the shell

    # Check if the output contains the expected output
    if [[ "$output" == *"$expected_output"* ]]; then
        echo "Test passed: '$command'"
    else
        echo "Test failed: '$command' - Expected: '$expected_output', Got: '$output'"
    fi
}

# Test 1: Check prompt display
echo "Testing prompt display..."
run_test "shell" "echo shell"

# Test 2: Change to home directory
echo "Testing change to home directory..."
run_test "$HOME" "cd ~; pwd"

# Test 3: Invalid command
echo "Testing invalid command..."
run_test "No such file or directory" "invalid_command"

# Test 4: List files in the current directory
echo "Testing 'ls' command..."
run_test "Makefile" "ls"  # Adjust based on your directory structure

# Test 5: Exit command
echo "Testing exit command..."
run_test "exit" "exit"  # Expect your shell to exit without error

# Add more tests as needed

echo "All tests completed."

