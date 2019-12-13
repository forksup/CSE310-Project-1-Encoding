# CSE310 Encoding Project
Project uses a clustering based compression algorithm to both encode and decode data. This script creates n left shifts each of one for any line of length n. Lines are alphabetically sorted by the last character using divide and conquer technique merge sort, then clusters are created from the last character.  

# Main Objectives
- Compare runtime of Merge sort vs Insertion sort
- Analyze compression ratio and compare performance for varying types of text

More info can be found in Report/Experimentation Report.pdf

Project definition and information can be found in Report/p1.pdf

Also a test input file was encoded, then decoded again and the results are in the Report folder. 

Usage: 

make encode
./encode <input.txt >output.txt

make decode 
./decode <input.txt >output.txt

