import subprocess
list_files = subprocess.run(["ls", "-l"], stdout=subprocess.DEVNULL)