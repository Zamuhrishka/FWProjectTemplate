import subprocess
import os
import shutil
import argparse

def determine_version(branch):
    if branch == "master":
        try:
            return get_git_output("git describe --abbrev=0")
        except subprocess.CalledProcessError:
            return "UNKNOWN"
    else:
        return "DEV"

def get_git_output(command):
    try:
        return subprocess.check_output(command, shell=True, text=True, stderr=subprocess.DEVNULL).strip()
    except subprocess.CalledProcessError:
        return "UNKNOWN"

def main(args):
    os.chdir(args.source_dir)

    commit = get_git_output("git describe --match=NeVeRmAtCh --always --abbrev=7")
    date = get_git_output(f"git show -s --format=%cd --date=format:%y_%m_%d {commit}")
    branch = get_git_output("git rev-parse --abbrev-ref HEAD")
    # ver = get_git_output("git describe --abbrev=0")
    ver = determine_version(branch)

    with open("version.h", "w") as f:
        f.write(f'#define FW_VER "{ver}"\n')
        f.write(f'#define COMMIT_NUMBER "{commit}"\n')
        f.write(f'#define COMMIT_DATE "{date}"\n')
        f.write(f'#define COMMIT_BRANCH "{branch}"\n')

    if args.action == "GIT":
        if ver == "UNKNOWN":
            print("Warning: No tags found in the repository. Version is set to 'UNKNOWN'.")
        print(f"version:{ver} Commit:{commit} Branch:{branch} Date:{date}")
    elif args.action == "SAVE":
        dest_filename = f"fw_{ver}_{branch}_{date}_{commit}.hex"
        source_filename = os.path.join(args.build_dir, "fw.ino.hex")
        print(f"Save {dest_filename} to {args.source_dir}")
        shutil.copy2(source_filename, dest_filename)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Manage firmware versions using Git. This script fetches Git information, creates a version.h file, and optionally saves the firmware hex file with a formatted name.")

    parser.add_argument("action", choices=["GIT", "SAVE"],
                        help="Action to perform: 'GIT' to print version info or 'SAVE' to copy the .hex file to the project directory.")

    parser.add_argument("build_dir",
                        help="Path to the temporary build directory. Used when action is 'SAVE' to locate the .hex file.")

    parser.add_argument("source_dir",
                        help="Path to the project's source files. This is where the version.h file will be created and where the .hex file will be saved if action is 'SAVE'.")

    args = parser.parse_args()
    main(args)
