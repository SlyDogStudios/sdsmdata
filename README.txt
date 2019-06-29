sdsmdata
Author: Robert L. Bryant
http://slydogstudios.org
slydogstudios@gmail.com


====================================================================
WHAT THIS PROGRAM DOES                                              |
====================================================================
Creates data to use for maps in 6502 assembly, along with some      |
relevant code to use. The labels that get spit out could be where   |
screen data gets placed, for instance. The bigger tables at the top |
of the file would be the overall map.                               |
====================================================================


====================================================================
COMPILING                                                           |
====================================================================
I use the GNU compiler for C++, g++. With this, it should build no  |
problem.                                                            |
                                                                    |
Windows: g++ -o sdsmdata.exe sdsmdata.cpp                           |
====================================================================


====================================================================
PLATFORMS                                                           |
====================================================================
This program has been compiled, tested, and confirmed to work on:   |
                                                                    |
Windows 8                                                           |
Windows 8.1                                                         |
====================================================================


====================================================================
DISCLAIMER                                                          |
====================================================================
I hold no responsibilities for this program doing anything to your  |
computer that is considered undesirable. You can use/modify the     |
source all you want, pass it on, etc. I have no beef with that at   |
all. If you do use the source for a project that you do, a simple   |
nod in my direction would be nice, but not necessary :)             |
====================================================================


====================================================================
USAGE                                                               |
====================================================================
The program can be used rather simply. It is terminal driven, which |
means you will have to pull up your command-line to use it. The     |
command to use the program is:                                      |
                                                                    |
sdsmdata <name of project> <length of map> <height of map>          |
                                                                    |
The breakdown for this is:                                          |
                                                                    |
sdsmdata                                                            |
    This is the name of the program obviously. If you named it      |
    something different, you will have to use that name.            |
                                                                    |
<name of project>                                                   |
    What you want the name of the project you are working on to be. |
    This will be used as part of a file that gets output by the     |
    program, and also used in parts of code that gets spit out      |
    inside of that same file.                                       |
                                                                    |
<length of map>                                                     |
    The overall width of the map you want to create data for. Should|
    be a number between 1 and 64.                                   |
                                                                    |
<height of map>                                                     |
    The overall height of the map you want to create data for.      |
    Should be a number between 1 and 64.                            |
                                                                    |
An example of using the program:                                    |
                                                                    |
sdsmdata myproject 30 16                                            |
                                                                    |
    This will create a file called myproject_map.asm. Inside, there |
    will be a couple of tables for hi and lo addresses, labels, two |
    tables for getting an offset that is bigger than 255, and a code|
    snippet to implement it.                                        |
                                                                    |
====================================================================


====================================================================
FUTURE VERSIONS                                                     |
====================================================================
Add checks to user input of arguments                               |
Change word "dummy" in output file to name of project               |
====================================================================

EOF