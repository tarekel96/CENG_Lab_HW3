# CENG_Lab_HW3

## Collaboration project between Tavid Terzian and Tarek El-Hajjaoui.

## Description of Program:
  -This is a C program that opens a file and logs an error or success message in the log.
  -Input the name of the file you wish to open in the cmd line when running the program.
  -If the file exists and is opened a success message will be put into the log file syslog
  -If the file does not exist of there was an error opening the file a failed message will be put into the logfile syslog
  -syslog is located in var/log path
  
## Instructions to run the program:
  -Compile with gcc: gcc syslog.c -o CustomNameHere
  -Run with command: ./CustomNameHere FileNameHere.extension
  
## Sources:
  -Linux Man page: https://linux.die.net/man/3/syslog
  -GNU: https://www.gnu.org/software/libc/manual/html_node/Syslog-Example.html
