# This file is not part of the module. It is provided as an extra to show what is possible. 
#
# The module has a copy of its output in its description field that can be read by "modinfo".
# This file can be used to read from "modinfo" to access the module output even if the module
# is not running. e.g. in another slot.

import subprocess
import glob

module_file = "/epm/epm.ko"

class read_module:
	def __init__(self, path=None, modinfoflags="-d"):
		self.output = ""
		self.err = ""
		self.out = {}
		self.path = ""
		if path:
			self.path = path

		pattern = self.path + "/lib/modules/*/kernel/drivers" + module_file
		f = glob.glob(pattern)
		if not f:
			return
		
		p = subprocess.Popen("modinfo %s %s" %( f[0], modinfoflags), stdout=subprocess.PIPE, shell=True)
		(self.output, self.err) = p.communicate()
		if self.output:
			for line in self.output.split("\n"):
				if "=" in line:
					line_split = line.split("=")
					self.out[line_split[0].strip()] = line_split[1].strip()

	def get(self, label):
		if label not in self.out:
			return ""
		return self.out[label]

# Example use					
if __name__ == "__main__":
	s = read_module()
	print s.get("getBoxType")
