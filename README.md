# CSE310 Encoding Project
Project uses a clustering based compression algorithm to both encode and decode data. This script creates n left shifts each of one for any line of length n. Lines are alphabetically sorted by the last character using divide and conquer technique merge sort, then clusters are created from the last character.  

Project definition and information can be found in p1.pdf


Usage: 

make encode
./encode <input.txt >output.txt

make decode 
./decode <input.txt >output.txt

