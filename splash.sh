#!/bin/bash

# ANSI Color Codes
RED="\033[0;31m"
GREEN="\033[0;32m"
BLUE="\033[0;34m"
YELLOW="\033[0;33m" # Gold
NC="\033[0m" # No Color

# Read file line by line
while IFS= read -r line
do
    # Read line char by char
    for (( i=0; i<${#line}; i++ ))
    do
        char="${line:$i:1}"

        # Check char and colorize accordingly
        case "$char" in
        "*") printf "$GREEN$char$NC";;
        "0") printf "$RED$char$NC";;
        "#") printf "$BLUE$char$NC";;
        "=") printf "$YELLOW$char$NC";;
        *) printf "$char";; # print without color if the character is not matched
        esac
    done

    # Print a newline character at the end of each line
    printf "\n"
    
    # Delay for 25 milliseconds
    sleep 0.0025
done < "n64-logo.txt"
