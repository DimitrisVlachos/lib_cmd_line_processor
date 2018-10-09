# lib_cmd_line_processor
Command line processor library

# Simple example :

    int main(int argc, char* argv) {
  
  
    cmd_line_arg_processor_c proc(argc,argv,true);
  
  
    //Assuming app was run with args binary.ext -int 1 -string hello -double 0.5
  
    while (proc.has_more()) {
  
        const std::string& op = proc.get_next_string();
    
        if (op == "null") {
            //some error
            return 1;
        }
    
        if (!proc.has_more()) {
            //some error
            return 1;
        }
    
        if (op == "-int")
            std::cout << "int = " << " << proc.get_next_int() << std::endl;
        else if (op == "-string")
            std::cout << "str = " << " << proc.get_next_string() << std::endl;
        else if (op == "-double")
            std::cout << "double = " << " << proc.get_next_double() << std::endl;
      
    }
    
    return 0;
  }

