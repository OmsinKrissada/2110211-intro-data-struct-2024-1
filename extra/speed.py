#!/usr/bin/env python3

import subprocess
import time
import shlex
import argparse
import random
import sys


def generate_data(begin: int, end: int):
    data = [x for x in range(begin, end)]
    random.shuffle(data)
    return " ".join([str(x) for x in data])


if __name__ == "__main__":
    file_name = "test"
    compile_command = f"g++-14 -x c++ -g -O2 -std=gnu++20 -pipe src/{file_name}.cpp -o bin/{file_name}"
    compile_begin = time.time()
    compile_process = subprocess.run(shlex.split(compile_command))
    compile_end = time.time()

    if compile_process.returncode != 0:
        exit(1)

    start = 0
    stop = 1000000  # exclusive
    step = 100000
    test_types = ["vector", "p-queue", "set", "multiset"]
    selected_test_types = [0, 1, 2]
    rounds_per_test = 3

    tests = []
    for i in range(start, stop, step):
        tests.append(i)

    results = {x: {} for x in selected_test_types}

    for i, n in enumerate(tests):
        bars = round((i + 1) / len(tests) * 40)
        # print("\n" * 30, file=sys.stderr)
        print(chr(27) + "[2J", file=sys.stderr)
        print(
            f"Testing with n = {n}\t[{'x'*bars}{'-'*(40-bars)}] {round((i+1)/len(tests)*100,2)}%",
            file=sys.stderr,
        )
        subtests = {x: [] for x in selected_test_types}
        for round in range(rounds_per_test):
            data = generate_data(0, n)
            for j in selected_test_types:
                prepared = f"{j} {n}"
                run_begin = time.time()
                process = subprocess.Popen(
                    f"./bin/{file_name}", stdin=subprocess.PIPE, stdout=subprocess.PIPE
                )
                output, _ = process.communicate(bytes(prepared, "utf-8"))
                run_end = time.time()

                subtests[j].append(run_end - run_begin)
        for k, v in subtests.items():
            results[k][n] = sum(v) / rounds_per_test
        del round

    print(f"size,{','.join([test_types[x] for x in selected_test_types])}")
    for i in tests[1:]:
        line = [str(i)]
        for j in selected_test_types:
            line.append(str(results[j][i]))
        print(",".join(line))
    # print(generate_data(10, 20))
