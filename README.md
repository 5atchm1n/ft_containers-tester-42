# 42 CONTAINERS TEST

#### STEP - 1
Read the makefile !

## Intro

A basic unit test for the 42 containers project, each container can be tested seperately.
Tests are split into thier respective directories, each test runs NTEST times and attempts
to modify the container at most MAX_TEST_SIZE.

Each test is run with a 10 different std::srand seeds, the base seed is 42.

The tests are wrapped in a switch case - the header file in each test folder contains
the necessary variables to modify the test.

Each test is stored in a array of functions pointers - and randomly called.

Feel free to add tests and remove tests to suit your build needs

#### BASIC USE

Modify the ```$INC``` variable in Makefile to point to your containers

### RUN TESTS

```make```              generate ft and std binaries (mandatory)

```make bonus```        generate ft and std binaries (mandatory + bonus)

```make test```         run test std vs ft

```make test_bonus```   run test std vs ft (mandatory + bonus)

```make test_all```      run each container tests individually

```make test_all_bonus``` run each container tests individually

#### TIME

```make time```  after ```make test_all```

```make time_bonus```  after ```make test_all_bonus```

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
all tests are run without ```$DEBUG``` and ```$MEM``` flags
to add them to ```make <rule_name> TMEM=1 TDEBUG=1```
if any of the tests fail Make will throw an error but still proceed
#### NOTE - to editors
create a branch and pull request to merge into master !
