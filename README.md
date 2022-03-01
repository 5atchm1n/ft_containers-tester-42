# 42_containers
Test suite for 42_containers

### STEP - 1
Read the makefile !

### BASIC
Modify the ```$INC``` variable in Makefile to point to your containers

#### BASIC COMMANDS

```make ft_vector```    to create ft::vector executable

```make std_vector```   to create std::vector executable

```make vector_test```  run test and output to /log

```make tclean```       clean test files

```make lclean```       clean log files

```make fclean```       clean all

check log folder for output

#### NOTE
all tests are run with ```$DEBUG``` and ```$MEM``` flags
if any of the tests fail Make will throw an error but still proceed

#### NOTE - to editors
create a branch and pull request to merge into master !