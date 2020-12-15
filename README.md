# CSE310 Encoding Project
Project uses a clustering based compression algorithm to both encode and decode data. This script creates n left shifts each of one for any line of length n. Lines are alphabetically sorted by the last character using divide and conquer technique merge sort, then clusters are created from the last character.

An example of encoded data can be found [input](https://github.com/forksup/CSE310-Project-1-Encoding/blob/master/Report/input.txt) [output](https://github.com/forksup/CSE310-Project-1-Encoding/blob/master/Report/outputencode.txt) 

# Main Objectives
- Compare runtime of Merge sort vs Insertion sort
- Analyze compression ratio and compare performance for varying types of text

My analysis of the various algorithms used can be found in [Experimentation Report.pdf](https://github.com/forksup/CSE310-Project-1-Encoding/blob/master/Report/Experimentation%20Report.pdf)

Project definition and information can be found in [p1.pdf](https://github.com/forksup/CSE310-Project-1-Encoding/blob/master/Report/p1.pdf)

Also a test input file was encoded, then decoded again and the results are in the Report folder. 

Usage: 

make encode
./encode <input.txt >output.txt

make decode 
./decode <input.txt >output.txt

