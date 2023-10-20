#!/usr/bin/env python3

import sys
import os
import argparse
import shutil
import subprocess

def ParseArguments():
    parser = argparse.ArgumentParser(
        prog='cmake.py',
        description='Script that calls cmake to build Makefiles and compile a C++ program. \
            Must be called from C++ project root directory.'
    )

    parser.add_argument('-x', '--clean',
                        action='store_true',
                        dest='clean',
                        help='Cleans compiles the C++ code.')
    
    return parser.parse_args()

def Main(arguments):
    if arguments.clean:
        if os.path.exists(os.path.join(os.getcwd(), 'bin')):
            shutil.rmtree(os.path.join(os.getcwd(), 'bin'))
            print('Cleaned C++ code successfully!')
            return 0
        else:
            print('Compiled code could not be found!')
    else:
        cmd = 'cmake -B ./bin -S ./ && cmake --build ./bin'
        process = subprocess.Popen(cmd,
                                   stdout=subprocess.PIPE,
                                   stderr=subprocess.STDOUT,
                                   shell=True
                                   )
        while process.poll() is None:
            print(process.stdout.readline().rstrip().decode('ascii'))
        return process.returncode

if __name__ == '__main__':
    arguments = ParseArguments()

    returnCode = Main(arguments)

    sys.exit(returnCode)
