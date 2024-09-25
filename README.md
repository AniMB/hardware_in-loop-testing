# Hardware-in-loop
Hardware in loop allows remote uploading of code onto STM32 boads without physical presence near the boards.

## Mission
This project uses a Raspberry Pi as a hub to remotely pull code from github and upload code to the STM32 board. The aim is to facilitate rapid development of code.

## Requirements
1. An STM32 board
2. A Raspberry Pi
3. Github Actions Runner
This can be setup by going to the setting -> actions -> runner as setup a linux runner. Follow the commands '''**except the last command**'''. 
4. Libraries
    - Setting up printf and scanf using this [website](https://shawnhymel.com/1873/how-to-use-printf-on-stm32/)
    - Installing OpenOCD using the code below
    ``` 
        git clone git://git.code.sf.net/p/openocd/code
        cd code/
        ./bootstrap
        ./configure
        make
        sudo make install
        cd ..
        rm -rf code/
        sudo touch /etc/udev/rules.d/stlink.rules
    ```
    Now paste this at the end of the file
    ```
    KERNEL=="tty[A-Z]*[0-9]", MODE="0666"
    SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", MODE="0666"
    ```
    - Install stlink
    ```
    sudo apt-get install stlink-tools
    ```
## Execution
The worklfow on the yaml file starts the moment a push is made to main. 
Add the `file paths` to the YAML file.
To execute this project to the location of the self hosted runner loaction and execute `./run/sh`.

## Precautions
Incase the runner is deleted, reinstall the runner at the same location. To do this, skip the `first command`. 
If you get an error while configuring, execute
```
ls -a
rm -f .runnner
rm -f config.sh
```





