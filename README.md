# ProcKill

A complimentary piece of code meant to run alongside malware that ensures that certain processes aren't running.

If a certain process is detected running (such as Process Hacker), it will kill the main malware running on the system & overwrite it to ensure the main malware can't be analyzed. ProcKill is meant to run in the background at all times so it is indeed noisy.

Go through the code & change code where comments say to change it (this is to ensure ProcKill knows where your malware is in order to be able to kill & overwrite it)

Main malware before analysis environment is detected:

![](/imgs/img1.png)

Main malware after analysis environment is detected:

![](/imgs/img2.png)

Command line output when analysis environment is detected:

![](/imgs/img3.png)

The reason for all the errors is due to the malware already being killed off & overwritten.

# Cross-Compiling

When cross-compiling using mingw, you may get an warning such as the one below, simply ignore it. It does not affect the way the code runs at all:

![](/imgs/img4.png)
