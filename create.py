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

import zipfile
import os

def extract_first_directory_with_files(zip_path, extract_to):
    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        # List of all files and directories in the zip
        all_files = zip_ref.namelist()

        # Dictionary to keep track of directories with files
        directories = {}

        for file in all_files:
            # Split the file path into parts
            parts = file.split('/')
            # Check if we have at least one file
            if len(parts) > 1:  # This means it's in a subdirectory
                dir_path = parts[0]
                if dir_path not in directories:
                    directories[dir_path] = []
                directories[dir_path].append(file)
            else:
                # This is a top-level file
                directories[''] = directories.get('', []) + [file]

        # Find the first directory that contains files
        for dir_path, files in directories.items():
            if files:
                # Extract the contents of the first directory found
                for file in files:
                    zip_ref.extract(file, extract_to)
                print(f'Extracted files from directory: {dir_path}')
                break
        else:
            print('No directory with files found.')

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
    extract_first_directory_with_files(f'src/{task_name}/archive.zip', TASK_DIR)
    
    # remove zip file
    os.remove(f'src/{task_name}/archive.zip')

    # move folders outside
    items = os.listdir(TASK_DIR)
    while len(items) == 1:
        abs_single = os.path.join(TASK_DIR, items[0])
        if not os.path.isdir(abs_single):
            break
        for n in os.listdir(abs_single):
            os.rename(os.path.join(abs_single, n), os.path.join(TASK_DIR, n))
        os.rmdir(abs_single)
        items = os.listdir(TASK_DIR)

    print('Done')
