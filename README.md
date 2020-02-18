# Sort Algorithm & Demo


## Directory

```shell
.
├── Makefile
├── obj
│   ├── sort_algo.o
│   └── test.o
├── README.md
├── run
└── src
    ├── sort_algo.c
    ├── sort_algo.h
    └── test.c
```

## Content
The source code contains of the following sort algorithm.

- **insert sort**
    - based on pointer
    - based on value

- **select sort**
    - based on pointer
    - based on value

- **bubble sort**
    - based on pointer
    - based on value

- **quick sort** based on pointer
    - using **k-medium** method
    - using **BFPRT** algorithm

- **heap sort** based on pointer

- **bucket sort** based on pointer

- **2-way merge sort** based on pointer

- **shell sort** based on pointer

- **BFPRT** algorithm

## Usage

Compile source code.

```shell
$ make
gcc -c ./src/test.c -o ./obj/test.o -g
gcc -c ./src/sort_algo.c -o ./obj/sort_algo.o -g
gcc ./obj/test.o ./obj/sort_algo.o -o run -lm
```

Run executable file.

```shell
$ ./run
algorithm   : insert sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 8.123493 S ]
have checked: pass
------------------------------------------------
algorithm   : select sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 13.073545 S ]
have checked: pass
------------------------------------------------
algorithm   : bubble sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 30.742655 S ]
have checked: pass
------------------------------------------------
algorithm   : heap sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 0.033225 S ]
have checked: pass
------------------------------------------------
algorithm   : quick sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 0.050058 S ]
have checked: pass
------------------------------------------------
algorithm   : bucket sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 0.011178 S ]
have checked: pass
------------------------------------------------
algorithm   : merge sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 0.017434 S ]
have checked: pass
------------------------------------------------
algorithm   : shell sort
size of set : 65536 = 64.000 K = 0.062 M
time of sort: [ 0.027086 S ]
have checked: pass
------------------------------------------------
```

Clear object files and executable file.

```shell
$ make clear
rm ./obj/*.o
```
