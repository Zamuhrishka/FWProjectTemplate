import os
import subprocess
import argparse

def format_files(source_dir):
    # Walk through the directory recursively
    for root, _, files in os.walk(source_dir):
        for file in files:
            if file.endswith(('.c', '.h', '.cpp', '.hpp')):
                filepath = os.path.join(root, file)
                # Format the file using clang-format
                subprocess.run(["clang-format", "-i", filepath])
                # Print the formatted file's path
                print(filepath)

def main():
    parser = argparse.ArgumentParser(description="Format C++ source files using clang-format.")
    parser.add_argument("source_dir", help="Path to the directory with source files to format.")

    args = parser.parse_args()
    format_files(args.source_dir)

if __name__ == "__main__":
    main()
