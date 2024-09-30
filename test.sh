#!/bin/bash

# Test cases for the custom shell

# Test 1: Check prompt display
echo "Test 1: Check prompt display"
echo "exit" | ./hsh
echo

# Test 2: Change directory to home
echo "Test 2: Change to home directory"
echo "cd ~; pwd" | ./hsh
echo

# Test 3: Change directory to a valid path
echo "Test 3: Change to a valid directory"
echo "cd /tmp; pwd" | ./hsh
echo

# Test 4: Attempt to change to an invalid directory
echo "Test 4: Change to an invalid directory"
echo "cd /invalid_path" | ./hsh
echo

# Test 5: List files in current directory
echo "Test 5: List files in current directory"
echo "ls" | ./hsh
echo

# Test 6: Print environment variables
echo "Test 6: Print environment variables"
echo "env" | ./hsh
echo

# Test 7: Exit command
echo "Test 7: Exit command"
echo "exit" | ./hsh
echo "Shell should exit now."

# Test 8: Handle unknown command
echo "Test 8: Handle unknown command"
echo "unknown_command" | ./hsh
echo

# Test 9: Check for a command with arguments
echo "Test 9: Check command with arguments"
echo "echo Hello, World!" | ./hsh
echo

# Test 10: Execute a command with logical operators
echo "Test 10: Execute command with logical operators"
echo "true && echo 'Success'" | ./hsh
echo "false || echo 'Failure'" | ./hsh
echo

# Test 11: Execute command with redirection
echo "Test 11: Execute command with redirection"
echo "echo 'This is a test' > testfile.txt" | ./hsh
echo "cat testfile.txt" | ./hsh
rm testfile.txt
echo

