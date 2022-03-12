# 42_containers
Test suite for 42_containers

### STEP - 1
Read the makefile !
### BASIC
Modify the ```$INC``` variable in Makefile to point to your containers

### RUN TESTS
```make```              generate ft and std binaries (mandatory)

```make bonus```        generate ft and std binaries (mandatory + bonus)

```make test```         run test std vs ft

```make test_bonus```   run test std vs ft (mandatory + bonus)

```make test_all``      run each container tests individually

```make test_all_bonus``` run each container tests individually

#### VECTOR
```make ft_vector```    to create ft::vector executable

```make std_vector```   to create std::vector executable

```make test_vector```  run vector test and output to /log
#### MAP
```make ft_map```		create ft::map executable

```make std_map```		create std::map executable

```make test_map```		run map test and output to /log
#### STACK
```make ft_stack```		create ft::stack executable

```make std_stack```	create std::stack executable

```make test_stack```	run stack test and output to /log
#### SET
```make ft_set```		create ft::set executable

```make std_set```		create std::set executable

```make test_set```		run set test and output to /log
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
