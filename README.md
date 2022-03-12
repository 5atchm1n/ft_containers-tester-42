# 42 CONTAINERS TEST
## A basic unit test for the 42 containers project

#### STEP - 1
Read the README !

## Intro

Each container can be tested seperately. Tests are split into their respective directories :
<ul>
<li> vector_test
<li> map_test
<li> stack_test
<li> set_test
</ul>

each test runs NTEST times and attempts to modify the container at most MAX_TEST_SIZE.

*These variables can be changed in the srcs/_test_header.hpp file*.

### MODIFYING THE TESTS

Each test is run MAX_SEED different times - the base SEED is 42.

The tests are wrapped in a switch case - the header file in each test folder contains
the necessary variables to modify the test. To remove a test for the unit comment out
the case in the given file and make the wanted binary again.

ex :

Each test is stored in a array of functions pointers - and randomly called.

Feel free to add tests and remove tests to suit your build needs

![scrnsht](https://user-images.githubusercontent.com/61289826/158004120-f8537caf-8fe0-4316-a21b-eee6b9cc16b7.png)
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
