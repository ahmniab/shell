# shell 
## Build
1 - clone the Repository 
```bash
git clone https://github.com/ahmniab/shell.git
```
2 - enter the following command to build and install shell
```bash
sudo make install clean
```

## Run 
enter the following command to run shell
```bash
shell
```
use man page for more help 
```bash
man shell
```

## configration
### shell.conf syntax
you can add your commands in shell.conf 
```
your_dos_command your_bash_command 
``` 
aka 
```
cls clear
dir ls
```

### shell.conf path
You can edit before building in 
```./conf/shell.conf```<br>
Or you can modify it after installing in 
```/etc/shell.conf```




## info
shell that accepts DOS commands and displays the output (results): 
Example: when user writes “dir”, the shell runs “ls” Command. Note: you 
have to use external text file for mapping between Linux and DOS 