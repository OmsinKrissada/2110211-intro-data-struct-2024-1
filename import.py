#!/usr/bin/env python3

import argparse
import os
import sys
import pathlib
import time
import zipfile

DOWNLOAD_FOLDER = os.path.join(pathlib.Path.home(), 'Downloads')

def getFilesSet():
    return set(os.listdir(DOWNLOAD_FOLDER))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Extract task zip into workspace")
    parser.add_argument(
        "task_name", type=str, help="Task name"
    )

    args = parser.parse_args()

    task_name = args.task_name

    TASK_DIR = f'src/{task_name}'

    if os.path.exists(TASK_DIR):
        print('Path already existed, terminating',file=sys.stderr)
        exit(1)

    # wait for zip file
    prev_files = getFilesSet()
    print(f'Watching download folder ({DOWNLOAD_FOLDER}) for a new zip file...')

    zip_file = None

    while(not zip_file):
        new_files = getFilesSet().difference(prev_files)
        if len(new_files):
            new_file = new_files.pop()
            if new_file.endswith('.zip'):
                zip_file = new_file
                print(f'Found {zip_file}')
        time.sleep(1)

    # create folder
    print(f'Creating directory {TASK_DIR}')
    os.mkdir(TASK_DIR)

    # move zip to folder
    print(f'Moving zip archive to folder')
    os.rename(os.path.join(DOWNLOAD_FOLDER, zip_file), f'src/{task_name}/archive.zip')

    # extract zip
    print('Extracting zip archive')
    with zipfile.ZipFile(f'src/{task_name}/archive.zip', 'r') as zip_ref:
        zip_ref.extractall(TASK_DIR)
    
    # remove zip file
    os.renames(f'src/{task_name}/archive.zip', f'trash/{int(time.time())}-{zip_file}')

    # move folders outside
    items = os.listdir(TASK_DIR)
    while len(items) == 1:
        abs_single = os.path.join(TASK_DIR, items[0])
        if not os.path.isdir(abs_single):
            break
        for n in os.listdir(abs_single):
            os.renames(os.path.join(abs_single, n), os.path.join(TASK_DIR, n))
        items = os.listdir(TASK_DIR)

    print('Done')
