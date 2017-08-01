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

