# CS580u Programming and System Tools
## Fall 2018
### PROGRAM 2 README FILE

## KNOWN BUGS AND INCOMPLETE PARTS:
- What parts of the program you were not able to complete

## REFERENCES:
- List any outside resources used

## MISCELLANEOUS COMMENTS:
- Anything you would like the grader to know

# Assignment Description
## Program 3 - Unix System Tools
### Due Date: 5:00 p.m., October 12th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Driver Code and Test Files

* program3.c
    * include the driver code with your submission, but do not alter it.
* hidden.o
    * object file for part 1

### Grading Rubric

**_TOTAL: 30 points_**

* **Part A: (5 points)**
    * Makefile has target memcheck that runs valgrind on program3 executable (2 points)
    * Passes Valgrind tests without memory leak or error (3 points)
* **Part B: (6 points)**
    * contains bomb_defused.txt with unique identifying key showing the bomb was defused (1 point)
    * contains phase key files for each phase (3 points)
    * Uses separate compilation, compiling program3.o and bomb.o to object files, then links all 3, including hidden.o, into an executable (2 points)
* **Part C: (9 points)**
    * bash script takes a list of command line arguments (1 point)
    * checks if all files exist (2 points)
    * creates keys directory if necessary (1 point)
    * appends contents of files to the last file in the list (3 points)
    * moves key files into key directory (2 points)
* **Part D: (8 points)**
    * Makefile has `all` dependencies that runs the `program3`, `clean`, and `submit` targets   (1 point)
    * Makefile has target that compiles the program3 executable using separate compilation (3 points)
    * Makefile has target for checkmem that compiles source to an executable and launches valgrind (1 points)
    * Makefile has target clean that removes object files (other than hidden.o) and executables, moves key files into the top level directory and dletes the key folder (2 points)
    * Makefile has a submit target that commits and pushes code to github (1 points)
* **Part D: (2 points)**
    * Follows requested program structure and submission format

### Guidelines

This is an individual assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

__In this program, you will learn to__:

* use unix system tools, such as Valgrind, make, gdb, and bash
* inspect your code and verify its validity

:warning: The provided code includes an object file, `hidden.o`, that was compiled on the machine in the lab. You must run your executable on the Q22 lab machines (you can do this remotely so you don't have to be _in_ lab).

Before we start working with the program itself, we will need to create a "makefile". We are going to add several targets to our makefile to help us along the way. The first target will simply compile the provided source code to an executable so you can complete the following parts of the assignments. A few things to note:
* You must use separate compilation.
    * First compile the program3.c and bomb.c files to an object file, then link both with hidden.o. to an executable
    * The hidden.o file has already been compiled to an object file, so you only need to link it.
* :warning: This must be completed with three separate targets, `program3` and `program3.o`, and `bomb.o`.
* :warning: remember to compile with the `-g` flag, otherwise gdb won't work.
* :no_entry_sign: Do not try to run this on your own machine. hidden.o was compiled on the lab machines and will not work on windows or mac.

## Part A: Fixing Memory Errors with Valgrind

The provided driver, `program3.c`, contains 3 functions riddled with memory errors, including a possible segmentation fault. You must use Valgrind to fix the code and ensure you have fixed all memory errors. Instead of running Valgrind directly, let's add another target to our makefile that will run Valgrind for us. To complete Part A, do the following:

* Add a target to your makefile, `memcheck`, that runs program3.c with Valgrind to inspect the memory errors.
* Fix all memory errors so that Valgrind reports no memory leaks and errors.
    * You should see the following once you have fixed all of the errors:
        ```bash
            All heap blocks were freed -- no leaks are possible
            ...
            ERROR SUMMARY: 0 errors from 0 contexts
        ```
* **CONSTRAINT**: You may alter the code in any line in the 3 functions, but you can not simply delete lines of code or change where memory is allocated.
    * For example, you can alter how much malloc() allocates, but cannot just delete malloc altogether.

## Part B: Defusing the Bomb with GDB

While you were fixing the code in Part A, the nefarious Dr. Evil has planted a "binary bomb" on our machines. A binary bomb is a program that consists of a sequence of phases. Each phase expects you to type a particular string on the standard input (stdin). If you type the correct string, then the phase is defused and the bomb proceeds to the next phase. Otherwise, the bomb explodes by printing "BOOM!!!" and then terminating. The bomb is defused when every phase has been defused. Your mission, which you have no choice but to accept, is to defuse your bomb before the due date.

Once you start execution of the program, you have **_200 seconds_** to defuse the bomb. Using GDB, step through the code, inspecting each passcode as you go. A few things to note:
* The passcodes are random and will change each time you execute, so you have to learn how to use GDB.
* Each phase’s passcode is the same length as the phase, so phase 1 only has a single letter passcode

A file will be produced for each phase you pass (phase1.key, phase2.key, etc). Once you have completed all 6 phases, a final file called `bomb_defused.log` will be generated. Make sure you include all of these files, **_unaltered_**, with your submission.


## Part C: Bash Scripting for Fun and Profit

Write a bash script called `bscript.sh` that takes a list of file names as arguments. The first list of files will be used to add content to the last file in the list, then the files will be moved into a directory called `keys`. For example, if you run the command:
```bash
./bscript.sh fileA fileB fileC fileD
```
The script will add the contents of fileA, fileB, and fileC to fileD, then move fileA, fileB, and fileC into a folder called `keys`

Your script should perform the following actions:
* verify that the file parameters exist
* If the files exist, the script should:
    * create a directory named `keys` that is located within the same directory as the script.
    * move all but the final file to the `keys` directory
    * add the contents of all the files in the `keys` directory to the last file
* If the given files do not exist, an appropriate error message should be printed and the script should end without doing anything.

You should be able to run your script as such:	./bscript.sh <filename1> <filename2> <filename3> ...
* :bulb: This means you will need to use the [`chmod`](https://ss64.com/bash/chmod.html) command to mark it as executable

Lastly, add a target, `bscript`, to your makefile that runs your script with the key files generated in Part B. The contents of the key files should be appended to the `bomb_defused.log` file.

### Part D: Makefile

When your program is complete, you should have the following targets

* all
    * all should have 3 targets as dependencies: program3, clean, and submit

* program3
    * Should compile the program3.c and bomb.c to separate object files, then link them with the provided hidden.o to create an executable.

* program3.o
    * Should compile program3.c to an object file

* bomb.o
    * Should compile program3.c to an object file

* bscript
    * first runs your executable code with gdb
    * runs your bash script you wrote in part C

* memcheck
    * runs your executable program3 with valgrind

* clean
    * The clean target removes any executable and object files you created when testing.
    * You should also move all phase keys back into the main folder and delete the key folder created with your bash script
    * :warning: Be careful you do not accidentally delete the provided object file hidden.o

* submit
    * You should commit a snapshot to your local git repo
    * push to github

## Part E: Submission

### Required file naming and organization:
* program3.c
* hidden.o
* bomb.c
* makefile
* bscript.sh
* bomb_defused.log
* keys/
    * phase1.key
    * phase2.key
    * phase3.key
    * phase4.key
    * phase5.key
    * phase6.key

:no_entry: Every program will have a required submission guidelines. Please read submission requirements carefully. Any deviations from specifications will result in point deductions or incomplete grades.

## README

* KNOWN BUGS AND INCOMPLETE PARTS
* REFERENCES
* MISCELLANEOUS COMMENTS

Before your final submission, edit the content for each of these sections in this README for your program. You do not have to use markdown, but you can find out more about markdown [here](https://guides.github.com/features/mastering-markdown/) if you would like to.

### Git

Below is a reminder of the commands you need to use to submit your program.

:warning: You have created several files and even a folder for this program. Be sure you add them to the repo. If you forget to add the files and the keys folder to the repo, your assignment will be considered late or not accepted at all.

```shell
git status
git add mylib.h
git commit -a -m "commit message"
git push
```

To find your most recent commit hash, use the following command:

```shell
git rev-parse HEAD
```    

To complete your submission, you must copy and paste this number into mycourses. Go to MyCourses, select cs580u, and **Assignment Hash Submission**.

:warning: You __MUST__ submit the commit hash on mycourses before the deadline to be considered on time **even if your program is completely working before the deadline**. :warning:
