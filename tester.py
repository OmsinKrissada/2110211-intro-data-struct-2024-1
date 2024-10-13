#!/usr/bin/env python3

import subprocess
import time
import shlex
import argparse
from os import path
import sys

input_filename = "data/in.txt"
output_filename = "data/out.txt"
generated_output_filename = "data/actual.txt"


def run_cpp_program(file_name):
    # Compile the C++ file
    if path.isfile(f"src/{file_name}.cpp"):
        src_file = f"src/{file_name}.cpp"
        bin_file = f"./bin/{file_name}"
    elif path.isdir(f"src/{file_name}"):
        src_file = f"src/{file_name}/main.cpp"
        bin_file = f"./bin/{file_name}"
    else:
        print(f"{file_name} does not exist", file=sys.stderr)
        return

    compile_command = f"g++-14 --std=c++17 -O2 {src_file} -o {bin_file}"
    compile_begin = time.time()
    compile_process = subprocess.run(shlex.split(compile_command))
    compile_end = time.time()

    if compile_process.returncode != 0:
        exit(1)

    # Execute the compiled program with input redirection
    # if os.stat(input_filename).st_size > 0:
    with open(input_filename, "r") as f:
        process = subprocess.Popen(bin_file, stdin=f, stdout=subprocess.PIPE)
        run_begin = time.time()
        output, _ = process.communicate()
        run_end = time.time()
    # else:
    #     output = input()

    # Write output to file
    with open(generated_output_filename, "w") as f:
        f.write(output.decode())

    # Compare output with expected output
    with open(output_filename, "r+") as f:
        expected_output = f.read().strip()
        # expected_file.write(expected_output)
        # print(expected_output)

    output = output.decode().strip()

    if expected_output:
        if output == expected_output:
            print("Results matched.")
        else:
            header = "Results don't match. To be correct, the following changes must be achieved."
            print(header)
            print("-" * len(header))
            with open(generated_output_filename, "r") as f, open(
                output_filename, "r"
            ) as f:
                # gen_lines = f.readlines()
                # exp_lines = expected_file.readlines()
                # diff = difflib.unified_diff(
                #     gen_lines, exp_lines, fromfile="generated.txt", tofile="out.txt"
                # )
                res = subprocess.run(
                    shlex.split(
                        f"diff --minimal --color=always {generated_output_filename} data/out.txt"
                    ),
                    stdout=subprocess.PIPE,
                )
                print(res.stdout.decode(), end="")
                # for line in res.stdout.decode().splitlines():
                #     print(line, end="")
    else:
        print(output)

    footer = f"{round(compile_end - compile_begin,2)}s compile | {round(run_end - run_begin,2)}s execute"
    print("-" * len(footer))
    print(footer)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compile and run a C++ program.")
    parser.add_argument(
        "filename", type=str, help="The name of the C++ source file without extension"
    )

    args = parser.parse_args()

    run_cpp_program(args.filename)
