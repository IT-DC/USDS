echo off
win_bison.exe -d -o bisonDictionaryTextParser.cc bisonDictionaryTextParser.y
python updateBisonOutput.py
win_flex.exe -o flexDictionaryTextScanner.cpp flexDictionaryTextScanner.l