
This repository is for create for Jupyter Xeus-Cling use.  
and install in docker buikd :  
https://github.com/Seachaos/docker-python-xeus-cling

This repository just simple handle opencv++ include and `imshow` for xeus-cling jupyter.

# Installation
assume all script is running by root because this project is made for Docker build.  

After you install OpenCV C++, can run
```shell
python3 ./install.py
```
It will scan opencv libs from `/usr/local/lib` 
and create include file for jupyter.


# Usage
In your jupyter notebook should can be use like this :
```c++
#include <jupyter/opencv>
using namespace cv;
Mat img = imread("./test.jpg");
imshow("cool", img);
```

example :
![demo image](https://github.com/Seachaos/opencv-cpp-for-xeus-cling/blob/master/notebook/demo.png)

