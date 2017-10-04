import io
import re

f = io.open("position.hh", 'r', encoding='utf8')
lines = []
for line in f:
	lines.append(line)
	if line == "    /// Compute max(min, lhs+rhs) (provided min <= lhs).\n":
		lines.append(u"#pragma warning(disable:4146)\n")
	
f.close()

f_out = io.open("position.hh", 'w', encoding='utf8')
for line in lines:
	f_out.write(line)
	
f_out.close()


f = io.open("flexCppTextReader.cpp", 'r', encoding='utf8')
lines = []
for line in f:
	line = re.sub("yyFlexLexer","yyFlexLexerCppTextReader", line)
	line = re.sub("yyalloc","yyallocCppTextReader", line)
	line = re.sub("yyfree","yyfreeCppTextReader", line)
	line = re.sub("yyrealloc","yyreallocCppTextReader", line)
	if line == "#include <FlexLexer.h>\n":
		lines.append(u"#include \"flexLexerCppTextReader.h\"\n")
	else:
		lines.append(line)
	
f.close()

f_out = io.open("flexCppTextReader.cpp", 'w', encoding='utf8')
for line in lines:
	f_out.write(line)
	
f_out.close()

