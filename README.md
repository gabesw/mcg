# Confluence Readme Sync
Command line tool for calculating McGill grades.

#### Contents
- [Overview](#overview)
- [Setup](#setup)
- [Usage](#usage)
- [Problems](#problems)

## Overview
This is a command line tool written in C by [@Gabesw](https://www.github.com/gabesw) to check a grade against the McGill grade scale.

## Setup
First, execute the installation script to compile the project and add it to the PATH:
```bash
$ sudo ./install
```

## Usage
| Command | Description | Example |
|----|----|----|
|mcg|Prints the McGill grade scale to the console.|mcg|
|mcg x/y|Calculates the letter grade of the evaluated fraction x/y and prints it.|mcg 18/20|
|mcg x|Calculates the letter grade corresponding to the numerical grade x/100 (e.g. x%). Decimals are allowed.|mcg 98.2|

## Problems
- The program does not round the grades.