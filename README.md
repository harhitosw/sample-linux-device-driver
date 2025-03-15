# A simple device driver for Linux
Attempting to understand how device drivers work and how one can be written. Started off with Linux Device Driver.

Used a multipass Ubuntu instance so that I don't screw up my machine.
`sudo snap install multipass`

Installed all the Linux headers :

`sudo apt install -y build-essential linux-headers-$(uname -r) kmod`

Built using `make`.

Inject Driver in Kernel using :

`sudo insmod ldd.ko`

When `user_space.py` is ran it tries reading from Driver file which is created and there a acknowledgement message in seen.