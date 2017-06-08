echo off
f:\Source\bison\win_bison.exe -d -o bisonDictionaryTextParser.cc bisonDictionaryTextParser.y
f:\Source\bison\win_flex.exe -o flexDictionaryTextScanner.cpp flexDictionaryTextScanner.l