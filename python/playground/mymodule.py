#import mypackage.utils
#from mypackage.utils import *
from mypackage.utils import multiply
import this
import inspect
import os

# Other modules on pypi.org:
# sudo apt install python-pip
# pip install requests

# Virtual environment:
# apt-get install python3-venv
# python3 -m venv myenv
# source myenv/bin/activate
# pip install requests

if __name__ == "__main__":
	print(multiply(2, 3))
#	print(mypackage.utils.multiply(2, 3))
	this_path = inspect.getfile(this)
	print("'this' is here: " + this_path)
#	print("/usr/lib/python3.6 contents:")
#	print(os.listdir("/usr/lib/python3.6/"))
	print("dir(multiply):\n" + str(dir(multiply))