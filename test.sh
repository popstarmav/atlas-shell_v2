#!/bin/bash

echo "Running Built-in Tests..."
./tests/test_builtins

echo "Running Command Exec Tests..."
./tests/test_command_exec

echo "Running Env Tests..."
./tests/test_env

echo "Running Logic Op Tests..."
./tests/test_logic_op

echo "Running Pipe Tests..."
./tests/test_pipe

echo "Running Redirection Tests..."
./tests/test_redirec
