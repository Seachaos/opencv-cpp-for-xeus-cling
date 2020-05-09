import os
from shutil import copyfile

LIBRARY_PATH = '/usr/local/lib/'

PREFIX = '/usr/local/include/jupyter'

INCLUDE_OPENCV_FILE_NAME = 'jupyter_opencv_include.h'

INCLUDE_PATH ="""
#pragma cling add_library_path("/usr/local/lib")
#pragma cling add_include_path("/usr/local/include/opencv4/")
#pragma cling add_include_path("/usr/local/include/")
//-----
"""


def find_opencv_library():
    result = []
    for name in os.listdir(LIBRARY_PATH):
        if 'libopencv' not in name:
            continue
        result += [name]
    return result


def make_include_file():
    content = INCLUDE_PATH
    # do scan opencv library
    for file_name in find_opencv_library():
        content += "#pragma cling load(\"{}\")\n".format(file_name)
    return content


def write_include_file():
    path = PREFIX + '/' + INCLUDE_OPENCV_FILE_NAME
    content = make_include_file()
    with open(path, 'w') as f:
        f.write(content)


write_include_file()

copyfile('./jupyter/opencv.hpp', PREFIX + '/opencv')