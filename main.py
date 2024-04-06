import json
import os
import subprocess 
        

def invoke_commands(dos : str) :
    params = dos.split()
    print(params)
    if params[0] in commands :
        if params[0] == 'cd' :
            os.chdir(params[1])
        else :
            subprocess.run(params)
            
            

def load_commands() -> dict:
    try:
        with open('cmd.json', 'r') as file:
            return json.loads(file.read())
    except FileNotFoundError :
        print("mapping file does not exists")
        exit(1)


commands = load_commands()

def main():
    invoke_commands('ls -l')
    # print('ls')

if __name__ == "__main__":
    main()