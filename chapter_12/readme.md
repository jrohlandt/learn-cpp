On ubuntu use apt to install libfltk1.3-dev
```
sudo apt-get update
sudo apt-get install libfltk1.3-dev
```

To compile a simple window:
```
g++ mywindow.cpp  -o mywindow -std=c++11 `fltk-config --ldflags`
```