# 42 CONTAINERS TEST
## A basic unit test for the 42 containers project

#### STEP - 1
Read the README !

Modify the ```$INC``` variable in Makefile to point to your containers

## Intro

Each container can be tested seperately. Tests are split into their respective directories :
<ul>
<li> vector_test
<li> map_test
<li> stack_test
<li> set_test
</ul>

Each test runs NTEST times and attempts to modify the container at most MAX_TEST_SIZE. The tests are run randomly using a unique seed to enable diff tests. The basic make commands ```all``` and ```bonus``` will compile the mandatory and bonus tests respectively.

To test the binaries output (std vs ft) run ```make test``` and suprise suprise to test the bonuses output
run ```make test_bonus```. These will run tests on all the containers simultaneously. Please read the section below to compile individual tests.

To run tests on all the binaries seperately run ```make test_all``` and ```make test_all_bonus``` this will run all the tests seperately and allow you to run the time commands to check the execution time.

*These variables can be changed in the srcs/_test_header.hpp file*.

### COMPILING INDIVIDUAL TESTS FOR DEBUGGING

*A full list of the rules is provided below*

each container can be compiled and tested using the following syntax :
```make [name]_[container]```

so to test ft vector you would excute :

```make ft_vector``` and this would generate the **ft_vector** binary.

```make std_vector``` would then generate the **std_vector** binary.

### RUNNING DIFF TESTS

*A full list of the rules is provided below*

each containers output can be tested against the std library using the folowing syntax :
```make test_[container]```

to test vector : ``` make test_vector```

### MODIFYING THE TESTS

Each test is run MAX_SEED different times - the base SEED is 42.

Each test is stored in a array of functions pointers - and randomly called.

The tests are wrapped in a switch case - the header file in each test folder contains
the necessary variables to modify the test. To remove a test for the unit comment out
the case in the given file and make the wanted binary again.

example for vector :

![scrnsht2](https://user-images.githubusercontent.com/61289826/158005653-54339d4f-d99d-497d-b0a6-cec9c4b7c27d.png)

Feel free to add tests and remove tests to suit your build needs

## BASIC USE
### RUN TESTS

```make```              generate ft and std binaries (mandatory)

```make bonus```        generate ft and std binaries (mandatory + bonus)

```make test```         run test std vs ft

```make test_bonus```   run test std vs ft (mandatory + bonus)

```make test_all```      run each container tests individually

```make test_all_bonus``` run each container tests individually

![scrnsht](https://user-images.githubusercontent.com/61289826/158004120-f8537caf-8fe0-4316-a21b-eee6b9cc16b7.png)

#### TIME

```make time```  after ```make test_all```

```make time_bonus```  after ```make test_all_bonus```

#### VECTOR

```make ft_vector``` to create ft::vector executable

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
