echo off
win_bison.exe -d -o bisonCppTextReader.cc bisonCppTextReader.y
win_flex.exe -o flexCppTextReader.cpp flexCppTextReader.l