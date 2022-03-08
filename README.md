# 42_containers
Test suite for 42_containers

### STEP - 1
Read the makefile !
### BASIC
Modify the ```$INC``` variable in Makefile to point to your containers
### RUN TESTS
#### VECTOR
```make ft_vector```    to create ft::vector executable

```make std_vector```   to create std::vector executable

```make test_vector```  run test and output to /log
#### MAP
```make ft_map```		create ft::map executable

```make std_map```		create std::map executable

```make test_map```		run test and output to /log
##### Clean
```make clean```		clean objs

```make tclean```       clean test files

```make lclean```       clean log files

```make fclean```       clean all

check log folder for output
#### NOTE
all tests are run with ```$DEBUG``` and ```$MEM``` flags
if any of the tests fail Make will throw an error but still proceed
#### NOTE - to editors
create a branch and pull request to merge into master !
