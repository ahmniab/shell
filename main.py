import json
import os
import subprocess 
        

def invoke_commands(dos) :
    if dos.strip() == "exit":
        exit(0)
    
    params = dos.split()
    if params[0] in commands :
        if params[0] == "cd" :
            if len(params) == 1 or params[1] == '~' :
                os.chdir(os.path.expanduser('~'))
            else :
                os.chdir(params[1])
            
        else :
            params[0] = commands[params[0]]
            subprocess.run(params)
    else :
        print("Invalid command ")        
            

def load_commands() -> dict:
    try:
        with open('cmd.json', 'r') as file:
            return json.loads(file.read())
    except FileNotFoundError :
        print("mapping file does not exists")
        exit(1)


commands = load_commands()

def main():
    while 1 :
        try :
            print(os.getcwd() + '>' , end=' ')
            invoke_commands(input())
        except KeyboardInterrupt :
            print()

if __name__ == "__main__":
    main()