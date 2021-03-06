# 42 FT_CONTAINERS TESTER
<sub> Inspired by [monkey_tester](https://github.com/jgiron42/ft_containers_monkey_tester) by [@jgiron42](https://github.com/jgiron42)</sub>


## A basic unit test for the 42 containers project
#### STEP - 1
Read the README !   
Compiles using clang++ !!  
Modify the ```$INC``` variable in [Makefile](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/Makefile) to point to your containers.  

NOTE - Modify the `#include "pair.hpp"` in the [srcs/_test_header.hpp](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/srcs/_test_header.hpp) to point to your ft::pair file if you wish to test map.


### BASIC
Just to get you started ! Read the [INDIVIDUAL TESTS](#COMPILING-INDIVIDUAL-TESTS-FOR-DEBUGGING) and [MODIFYING TESTS](#MODIFYING-THE-TESTS) for
details on how to debug errors or run individual tests.

```make test_[container] ``` to test against std ( *ex:* `make test_vector` )

```make test_all ``` to run all tests at once.

NOTE - *A full list of the [commands](#COMMANDS) is provided below*  
NOTE - *All test variables can be changed in the [srcs/_test_header.hpp](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/srcs/_test_header.hpp) file*  
NOTE - *Tests can be run with or without certain options. ex: -fsanitize=address can be removed. Please check [makefile variables](#VARIABLES) for the details.*  
## Intro
Each container can be tested seperately. Tests are split into their respective directories :
<ul>
<li> vector_test
<li> map_test
<li> stack_test
<li> set_test
</ul>

Each test runs NTEST times and attempts to modify the container at most MAX_TEST_SIZE. The tests are run randomly using a unique SEED and this MAX_SEED_SIZE times to ensure multiple random test that can be run identicaly with the std library.  
<sub>NOTE - *All test variables can be changed in the [srcs/_test_header.hpp](https://github.com/5atchm1n/ft_containers-tester-42/blob/master/srcs/_test_header.hpp) file*</sub>

[Test all containers together](#FULL-TESTS-SINGLE-BINARY)  
[Test all containers seperately](#FULL-TEST-SEPERATE-BINARIES)  
### COMPILING INDIVIDUAL TESTS FOR DEBUGGING  
<sub> <b>NOTICE - as of now you must run make clean between commands </b> </sub>  
<sub>*A [full list](#COMMANDS) of the rules is provided below*</sub>  
<sub> Please check [makefile variables](#VARIABLES) </sub>

each container can be compiled and tested using the following syntax :

```make [name]_[container]```  

so to test ft vector you would excute :  

```make ft_vector``` and this would generate the **ft_vector** binary.  

```make std_vector``` would then generate the **std_vector** binary.  

each containers output can be tested against the std library using the folowing syntax :  

```make test_[container]```  

to test vector : ```make test_vector```
## MODIFYING THE TESTS

Tests can be run with or without certain compile flags. The const test can also be removed. Please check [makefile variables](#VARIABLES) for the details.  
Each test is run MAX_SEED different times - the base SEED is 42.
Each test is stored in a array of functions pointers - and randomly called.
The tests are wrapped in a switch case - the header file in each test folder contains the necessary variables to modify the test. To remove a test for the unit comment out the case in the given file and make the wanted binary again.  

example for vector :

![scrnsht2](https://user-images.githubusercontent.com/61289826/158005653-54339d4f-d99d-497d-b0a6-cec9c4b7c27d.png)  
Feel free to add tests and remove tests to suit your build needs
#### FULL TESTS - SINGLE BINARY

The basic make commands ```all``` and ```bonus``` will compile the mandatory and bonus tests respectively.  
To run diff tests (std vs ft) run ```make test``` and suprise suprise to test the bonuses output
run ```make test_bonus```. These will run tests on all the containers simultaneously. Please read the sections below to compile individual tests.

#### FULL TESTS - SEPERATE BINARIES

To run diff tests on all the binaries seperately run ```make test_all``` and ```make test_all_bonus``` this will run all the tests seperately and allow you to run the time commands to check the execution time.  
If any of the tests fail Make will throw an error and stop.  
Logs are output to the log directory and all tests are run with -fsanitize=address and -fstandalone-debug  
<sub>*this can be changed please read NOTES section*</sub>
## COMMANDS
#### FULL PROJECT TESTING  
```make```              generate ft and std binaries (mandatory)  
```make bonus```        generate ft and std binaries (mandatory + bonus)  
```make test```         run test std vs ft  
```make test_bonus```   run test std vs ft (mandatory + bonus)  
```make test_all```      run each container tests individually  
```make test_all_bonus``` run each container tests individually

![containers_tester](https://user-images.githubusercontent.com/61289826/158044256-5ee131c2-3317-4d57-8826-dbe8e8283ed7.png)  
#### TIME
```make time```  after ```make test_all```  
```make time_bonus```  after ```make test_all_bonus```
### INDIVIDUAL CONTAINERS TESTS
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
#### Clean
```make clean```		clean objs  
```make tclean```       clean test files  
```make lclean```       clean log files  
```make fclean```       clean all  
#### VARIABLES
you can enable and disable certain tests at compile time by running the make command using certain variables.
<ul>
<li> <b>TMEM</b> - removes -fsanitize=address </li>
<li> <b>TDEBUG</b> - removes -fstandalone-debug </li>
<li> <b>TCONST</b> - removes const only tests </li>
<li> <b>TALLOC</b> - set to 1 to add allocator tests </li>
<li> <b>LOG</b> - output diff to stdout and file (no seperate logs)</li>
</ul>
these variables can be used together ex:

```make <rule_name> TMEM=0 TCONST=0 TALLOC=1```

#### NOTE - to editors
create a branch and pull request to merge into master !
