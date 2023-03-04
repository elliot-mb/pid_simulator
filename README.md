# PID Simulator

Aim to create basic 2D component-based physics with constraints, rendered using OpenGL, with the eventual goal of being able to simulate closed-loop control systems like PID controllers.

This project is my first in c++, and was inspired at least in part by [Ange-the-great](https://github.com/ange-yaghi/scs-2d-demo) as seen on YouTube, famous for his c++-based Engine Simulator. 

### Dependencies

The dependancies of this project include:
- GLM
- glad (included at top-level as a c file, and installed as a header)
- GLFW
- make

### Compile and run 

``make clear`` removes any files that remain from previous compliations. Please run this in a new directory in case you delete important files by mistake.

``make out`` tries to compile all files according to their dependance on each other. These get linked into a single executable ``out`` at top-level, if successful.

``chmod 700 out && ./out`` will run the executable.

I'm completing this project on Ubuntu, and as such have not tested its functionality or behaviour on Windows etc.
```
❯ lsb_release -a
No LSB modules are available.
Distributor ID:	Ubuntu
Description:	Ubuntu 22.04.2 LTS
Release:	22.04
Codename:	jammy
```
