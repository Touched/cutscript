import sys
import re

def err_exit_msg(message):
     sys.stderr.write(message + "\n")
     sys.exit()


commands = {'bg_load' : 1, 'oam_create': 2, 'set_var': 3, 'add_var': 4, 'goto': 8}
flags = {'var': 1}



if __name__ == "__main__":
     with open('/script') as f:
          lines = f.read().splitlines()
     
          
          #lines = ["bg_load var(5) 6 var(4)", "set_var var(2) 5", "LABEL1:", 
          #          "oam_create 3 5 var(87)", "goto LABEL1"]
          
          #commands look like:
          #command flag(arg), arg, flag(arg), arg, arg
          
          compiled = ""
          line_count = 1
          labels = []
          for element in lines:
               temp = element.split(" ")
               
               #first word is the command
               if (commands.get(temp[0])):
                    compiled += str(commands.get(temp[0]))
                    
               elif((str(temp[0])).__contains__(":")):
                    #label, however the hell you're supposed to parse this, do
                    #that stuff over here :D
                    label_tuple = (str(temp[0]).strip(":"), line_count)
                    labels.append(label_tuple)
                    
               else:
                    
                    err_exit_msg("Invalid command: '" + str(temp[0]) + 
                                 "' in line " + str(line_count) + ".")
                    exit()
                    
               temp2 = temp[1:]
               #remaining list is either an arg or flagged arg. Process
               for arg in temp2:
                    flag = re.search('.*\(.*\)', arg)
                    if flag:
                         flag_arg = flag.group(0).split("(")
                         flag_arg[1] = flag_arg[1].strip(")")
                         
                         #check flag is valid, process
                         if (flags.get(flag_arg[0])):
                              compiled += (str(flags.get(flag_arg[0])))
                              compiled += str(flag_arg[1])
                              
                         else:
                              err_exit_msg("Invalid flag: " + str(flag_arg[0]) + 
                                           " in line" + str(line_count) + ".")
                         
                    else:
                         for label in labels:
                              if (label[0] == str(arg)):
                                   compiled += "0" + str(label[1])
                                   arg = None
                                   
                         if (arg):
                              compiled += "0" + str(arg)
               line_count += 1
                         
          print(str(compiled))
                    
                         
                    
                         